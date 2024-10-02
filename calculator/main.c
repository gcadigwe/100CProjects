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

	int n = argc - 1;

	if (n <= 0) {
		 printf("Error: Array size must be a positive integer.\n");
        return 1;
	}

	//dynamically allocate memory for 'n' integers using malloc
	char **arr = (char **)malloc(n * sizeof(char *));
	if (arr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }

	for(int i = 0; i < argc - 1 ; i++){
		arr[i] = (char *)malloc((strlen(argv[i + 1]) + 1) * sizeof(char));
		 if (arr[i] == NULL) {
            fprintf(stderr, "Error: Memory allocation for argument %d failed.\n", i);
            exit(EXIT_FAILURE);
        }
		strcpy(arr[i], argv[i + 1]);

	}

	char input[256] = ""; // Buffer to hold the concatenated string
    for (int i = 0; i < n; i++) {
        strcat(input, arr[i]);
        // if (i < n - 1) {
        //     strcat(input, " "); // Add space between arguments
        // }
    }
	printf("%s\n", input);

	int index = find_operator(input);
    
    if (index != -1) {
        printf("Index of operator: %d\n", index);
		int input1 = input[index-1] - '0';
		int input2 = input[index+1] - '0';

		int result = handle_calculation(input[index], input1 ,input2);
		printf("Result: %d\n", result);
    } else {
        printf("No operator found in the input.\n");
    }



	// for (int i = 0; i < n; i++) {
    //     printf("%s\n", arr[i]);
    // }


	// printf("Array elements: ")
   for (int i = 0; i < n; i++) {
        free(arr[i]); // Free each string
    }
	free(arr);

	return 0;
}
