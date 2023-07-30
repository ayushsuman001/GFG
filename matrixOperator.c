#include<stdio.h>
#include<stdlib.h>

//Addition
void add(int m[3][3], int n[3][3], int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==r2 && r2==c2){
    for(int i=0;i<r1;i++)
      for(int j=0;j<r2;j++)
        final[i][j] = m[i][j] + n[i][j];
  }
  else{
    printf("Order of both matrix must be same");
  }
}

//Subtraction
void subtract(int m[3][3], int n[3][3], int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==r2 && r2==c2){
    for(int i=0;i<r1;i++)
      for(int j=0;j<r2;j++)
        final[i][j] = m[i][j] - n[i][j];
  }
  else{
    printf("Order of both matrix must be same");
  }
}

//Multiply-Scalar
void multiply_scalar(int m[3][3], int n, int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==c2){
    for(int i=0; i < r1; i++)
    {
      for(int j=0; j < c2; j++)
      {
        final[i][j] = m[i][j] * n;
      }
    }
  }
  else{
    printf("rows of first  matrix must be equal to columns of second matrix");
  }
}

//Multiply-Matrix
void multiply(int m[3][3], int n[3][3], int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==c2){
    for(int i=0; i < r1; i++)
    {
      for(int j=0; j < c2; j++)
      {
        final[i][j] = 0;
        for (int k = 0; k < r2; k++)
          final[i][j] += m[i][k] * n[k][j];
      }
    }
  }
  else{
    printf("rows of first  matrix must be equal to columns of second matrix");
  }
}

//Division-Scalar
void divide_scalar(int m[3][3], int n, int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==c2){
    for(int i=0; i < r1; i++)
    {
      for(int j=0; j <c2; j++)
      {
        final[i][j] = m[i][j] / n;
      }
    }
  }
  else{
    printf("rows of first  matrix must be equal to columns of second matrix");
  }
}

//Division-Matrix
void divide(int m[3][3], int n[3][3], int r1, int c1, int r2, int c2, int final[3][3])
{
  if (r1==c2){
    for(int i=0; i < r1; i++)
    {
      for(int j=0; j < c2; j++)
      {
        final[i][j] = 0;
          for (int k = 0; k < r2; k++)
            final[i][j] += m[i][k] / n[k][j];
      }
    }
  }
  else{
    printf("rows of first  matrix must be equal to columns of second matrix");
  }
}

//Transpose
void transpose(int matrix[3][3], int final[3][3])
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      final[i][j] = matrix[j][i];
}

//Inverse
void inverse(int matrix[3][3],int final[3][3]){}

//Print
void print(int matrix[3][3])
{
  for(int i=0; i<3; i++)
  {
    for(int j=0; j<3; j++)
      printf("%d\t",matrix[i][j]);

    printf("\n");
  }
}

// _main_ starts
int main()
{
    int r1,c1,r2,c2,choice,n;
    printf("Enter the no. of rows for 1st matrix: ");
    scanf("%d",&r1);
    printf("Enter the no. of columns for 1st matrix: ");
    scanf("%d",&c1);    
    printf("Enter the no. of rows for 2nd matrix: ");
    scanf("%d",&r2);    
    printf("Enter the no. of columns for 2nd matrix: ");
    scanf("%d",&c2);
    int m1[r1][c1],m2[r2][c2];
    printf("Enter the values for 1st matrix: ");
    for (int i=0;i<r1;i++){
        for (int j=0;j<c1;j++){
            scanf("%d",&m1[i][j]);
        }
    }
    printf("Enter the values for 2nd matrix: ");
    for (int i=0;i<r2;i++){
        for (int j=0;j<c2;j++){
            scanf("%d",&m2[i][j]);
        }
    }
    int final[r1][c2];
  printf("First Matrix:\n");
  print(m1);
  printf("Second Matrix:\n");
  print(m2);

  do
  {

    printf("\nSelect from the below : \n");
    printf("----------------------------\n");
    printf("0. Print the matrix\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication with a scalar\n");
    printf("4. Multiplication with a matrix\n");
    printf("5. Division by a scalar\n");
    printf("6. Division by a matrix\n");
    printf("7. Transpose of a matrix\n");
    printf("8. Inverse of a matrix\n");
    printf("9. Exit\n");
    printf("----------------------------\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 0:
        printf("First Matrix:\n");
        print(m1);
        printf("Second Matrix:\n");
        print(m2);
        break;
      case 1:
        add(m1, m2, r1, c1, r2, c2, final);
        printf("Sum of matrix: \n");
        print(final);
        break;
      case 2:
        subtract(m1, m2, r1, c1, r2, c2, final);
        printf("Subtraction of matrix: \n");
        print(final);
        break;
      case 3:
       //int n;
        printf("Enter the scalar value: ");
        scanf("%d",&n);
        int ch;
        printf("Select the matrix to be multiplied: ");
        printf("1. 1st matrix");
        printf("2. 2nd matrix");
        scanf("%d",&ch);
        switch (ch){
          case 1:
            multiply_scalar(m1, n, r1, c1, r2, c2, final);
            break;
          case 2:
            multiply_scalar(m2, n, r1, c1, r2, c2, final);
            break;
          default:
            printf("Invalid Choice!");
        }
        printf("Multiplication with a scalar: \n");
        print(final);
        break;
      case 4:
        multiply(m1, m2, r1, c1, r2, c2, final);
        printf("Multiplication with a matrix: \n");
        print(final);
        break;
      case 5:
        printf("Enter the scalar value: ");
        scanf("%d",&n);
        int ch1;
        printf("Select the matrix to be divided: ");
        printf("1. 1st matrix");
        printf("2. 2nd matrix");
        scanf("%d",&ch1);
        switch (ch1){
          case 1:
            divide_scalar(m1, n, r1, c1, r2, c2, final);
            break;
          case 2:
            divide_scalar(m2, n, r1, c1, r2, c2, final);
            break;
          default:
            printf("Invalid Choice!");
        }
        printf("Division by a scalar: \n");
        print(final);
        break;
      case 6:
        divide(m1, m2, r1, c1, r2, c2, final);
        printf("Division by a matrix: \n");
        print(final);
        break;
      case 7:
        printf("Transpose of the first matrix: \n");
        transpose(m1, final);
        print(final);
        printf("Transpose of the second matrix: \n");
        transpose(m2, final);
        print(final);
        break;
      case 8:
        printf("Inverse of the first matrix: \n");
        inverse(m1, final);
        print(final);
        printf("Inverse of the second matrix: \n");
        inverse(m2, final);
        print(final);
        break;
      case 9:
        printf("----------------------------\n");
        printf("Thank You.\n");
        printf("----------------------------\n");
        exit(0);
      default:
        printf("Invalid input.\n");
        printf("Please enter the correct input.\n");
    }
  }while(1);

  return 0;
}