#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

int find_operator(const char *arr){
	const char operators[] = "+-/*";
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



int add(int input1, int input2) {
	printf("%d, %d\n", input1,input2);
	return input1 + input2;
}

int handle_calculation(char operator, int input1, int input2) {
	switch(operator) {
		case '+': {
			int result = add(input1, input2);
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

    // Free allocated memory
 

	// int n = argc - 1;

	// if (n <= 0) {
	// 	 printf("Error: Array size must be a positive integer.\n");
    //     return 1;
	// }

	//dynamically allocate memory for 'n' integers using malloc
	// char **arr = (char **)malloc(n * sizeof(char *));
	// if (arr == NULL) {
    //     fprintf(stderr, "Error: Memory allocation failed.\n");
    //     exit(EXIT_FAILURE);
    // }

	// for(int i = 0; i < argc - 1 ; i++){
	// 	printf("args %s\n", argv[i + 1]);
	// 	if (strcmp(argv[i + 1], " ") == 0) {
	// 		printf("space found");
    //     	continue;  // Skip the empty string
    // 	}
	// 	arr[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
	// 	 if (arr[i] == NULL) {
    //         fprintf(stderr, "Error: Memory allocation for argument %d failed.\n", i);
    //         exit(EXIT_FAILURE);
    //     }
	// 	strcpy(arr[i], argv[i + 1]);

	// }

	// char input[4] = "";
    // for (int i = 0; i < n; i++) {
    //     strcat(input, arr[i]);
    // }
	// printf("%s\n", input);

	int index = find_operator(result);
    
    if (index != -1) {
		int input_size = strlen(result);
		printf("index %d\n", index);
		printf("size %d\n", input_size);
		int size_before = index;
		int size_after =  input_size - index - 1;

		char* before_arr = (char *) malloc(size_before * sizeof(char)); 

		char* after_arr = (char *)malloc(size_after * sizeof(char));

		// before_arr[0] = '\0';
		 // Copy elements before the index
   		 for (int i = 0; i < size_before; i++) {
			printf("before %c\n", result[i] );
			// strcpy(before_arr[i], result);
        	before_arr[i] = result[i];
			before_arr[i + 1] = '\0';

   		 }
    
   		 // Copy elements after the index
    	for (int i = index + 1; i < input_size; i++) {
       		 after_arr[i - index - 1] = result[i];
			 after_arr[i - index - 1 + 1] = '\0';  // Shift left by the index+1
   		 }
    
		//  Print the 'before' array
   		 printf("Array before the index: ");
   		 for (int i = 0; i < size_before; i++) {
        	printf("%c", before_arr[i]);
   		 }
   		 printf("\n");
    
    	// Print the 'after' array
    	printf("Array after the index: ");
    	for (int i = 0; i < size_after; i++) {
        	printf("%c", after_arr[i]);
   		 }

		  printf("\n");
        printf("before array: %s\n", before_arr);
		int input1 = atoi(before_arr);
		int input2 = atoi(after_arr);

		int calc_result = handle_calculation(result[index], input1 ,input2);
		printf("Result: %d\n", calc_result);
		free(before_arr);
		free(after_arr);
    } else {
        printf("No operator found in the input.\n");
    }

	// printf("Array elements: ")
//    for (int i = 0; i < n; i++) {
//         free(arr[i]); // Free each string
//     }
// 	// free(arr);
	   free(result);
	// free(input2);

	return 0;
}
