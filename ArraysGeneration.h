
#ifndef ARRAY_GENERATION
#define ARRAY_GENERATION


///generating mines in editor's array
void mineGeneration(int rowNum, int colNum, char editorArray[rowNum][colNum],int rowNumberofMine[91],int colNumberOfMine[91],int num1,int num2);
///generating number in editor's array
void numberGeneration(int row, int col, int minesNumber,char editorArray[row][col],int rowNumberofMine[91],int colNumberOfMine[91]);
///generating user's array with 'X' as closed cells.
void generateUserArray(int row, int col, char userArray[row][col]);
///generating spaces in the array
void initialArrayGeneration(int row, int col, char editorArray[row][col]);



#endif
