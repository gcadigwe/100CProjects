#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#define MAX_LEN 100

int find_operator(const char *arr,const char *operators ){
	for (int i = 0; arr[i] != '\0'; i++) {
		for (int j = 0; operators[j] != '\0'; j++ ){
			if(arr[i] == operators[j]) {
				printf("operator  %c\n", arr[i]);
				return i;
			}
		}
	}

	return -1;
}

int check_appearance(const char *str1, const char *str2, int *indices, int *operator_indexes) {
    int count = 0;

    // Loop through each character in str2
    for (int i = 0; i < strlen(str2); i++) {
        // Check if the current character of str2 exists in str1
        for (int j = 0; j < strlen(str1); j++) {
            if (str2[i] == str1[j]) {
                // If there's a match, store the index from str1 and increase count
                indices[count] = j;
				operator_indexes[count] = i;
				count++;
                // break; // To avoid counting multiple matches of the same character in str2
            }
        }
    }

    return count; // Return the number of matches found
}



int add(int input1, int input2) {
	printf("%d, %d\n", input1,input2);
	return input1 + input2;
}

int sub(int input1, int input2) {
	printf("%d, %d\n", input1,input2);
	return input1 - input2;
}

int divide(int input1, int input2) {
	printf("%d, %d\n", input1,input2);
 	if (input1 == 0 || input2 == 0) {
        fprintf(stderr, "Error: Cannot divide with 0.\n");
        return 1;
    }

	return input1 / input2;
}

int multiply(int input1, int input2) {
	printf("%d, %d\n", input1,input2);

	return input1 * input2;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to rearrange the array with the highest index first
void rearrange_highest_first(int *arr,int *arr2, int n) {
    int max_index = 0;

    // Find the index of the largest element in the array
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[max_index]) {
            max_index = i;
        }
    }

    // Swap the largest element with the first element
    if (max_index != 0) {
        swap(&arr[max_index], &arr[0]);
		printf("max index %d\n", max_index);
		swap(&arr2[max_index], &arr2[0]);
    }
}

int handle_calculation(char operator, int input1, int input2) {
	switch(operator) {
		case '+': {
			int result = add(input1, input2);
			return result;
			break; 
		}	
		case '-': {
			int result = sub(input1, input2);
			return result;
			break; 
		}	
		case '/': {
			int result = divide(input1, input2);
			return result;
			break; 
		}	
		case '*': {
			int result = multiply(input1, input2);
			return result;
			break; 
		}		
		default:
			printf("No implementation for operator yet");
			return 0;
	}

}



int main(int argc, char *argv[]){

	if(argc < 3){
		fprintf(stderr, "Error: There should be more than one inputs.\n");
        exit(EXIT_FAILURE);  
	}

	int total_length = 0;
    for (int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]);
    }

	char *result = (char *)malloc((total_length + 1) * sizeof(char));
    if (result == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return 1;
    }

	result[0] = '\0';

	for (int i = 1; i < argc; i++) {
        strcat(result, argv[i]);
    }

	printf("Concatenated string: %s\n", result);
	const char *operators = "-+*/";

	int indices[MAX_LEN]; // To store the indices of matching characters from str1
	int operator_indexes[MAX_LEN];
    int match_count;
	match_count = check_appearance(result,operators, indices, operator_indexes);

	 printf("Number of matching characters: %d\n", match_count);
    if (match_count > 0) {
		
        printf("Before arranged: ");
        for (int i = 0; i < match_count; i++) {
            printf("%d %d \n", indices[i],operator_indexes[i]);
			//  printf("%d ", operator_indexes[i]);
        }
		// rearrange_highest_first(indices, match_count);
		rearrange_highest_first(operator_indexes,indices, match_count);
        // printf("\n");
		 printf("Rearranged indices: ");
    		for (int i = 0; i < match_count; i++) {
        		printf("%d %d ", indices[i],operator_indexes[i]);
				
   			 }
    printf("\n");
    } else {
        printf("No matching characters found.\n");
    }

	// int index = find_operator(result, operators);
    
    // if (index != -1) {
	// 	int input_size = strlen(result);
	// 	int size_before = index;
	// 	int size_after =  input_size - index - 1;

	// 	char* before_arr = (char *) malloc(size_before * sizeof(char)); 

	// 	char* after_arr = (char *)malloc(size_after * sizeof(char));

	// 	// before_arr[0] = '\0';
	// 	 // Copy elements before the index
   	// 	 for (int i = 0; i < size_before; i++) {
	// 		printf("before %c\n", result[i] );
	// 		// strcpy(before_arr[i], result);
    //     	before_arr[i] = result[i];
	// 		before_arr[i + 1] = '\0';

   	// 	 }
    
   	// 	 // Copy elements after the index
    // 	for (int i = index + 1; i < input_size; i++) {
    //    		 after_arr[i - index - 1] = result[i];
	// 		 after_arr[i - index - 1 + 1] = '\0';  // Shift left by the index+1
   	// 	 }
    
   	// 	 for (int i = 0; i < size_before; i++) {
    //     	printf("%c", before_arr[i]);
   	// 	 }
   
    
    	
    // 	for (int i = 0; i < size_after; i++) {
    //     	printf("%c", after_arr[i]);
   	// 	 }

	// 	int input1 = atoi(before_arr);
	// 	int input2 = atoi(after_arr);

	// 	int calc_result = handle_calculation(result[index], input1 ,input2);
	// 	printf("Result: %d\n", calc_result);
	// 	free(before_arr);
	// 	free(after_arr);
    // } else {
    //     printf("No operator found in the input.\n");
    // }


	   free(result);

	return 0;
}


