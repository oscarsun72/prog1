#pragma once
size_t count_calls(size_t i);
int factoral(int f) 	;
void fact() ;
void absv(int ab);
void SwapTwoInt(int* ip1,int *ip2);//�m��6.10
int resetVal(int& r);//�m��6.11
void SwapTwoInt(int& ir1, int& ir2);//�m��6.12
int returnLarger(int i, int* ip);//�m��6.21
void swap_two_pointers(int*& i, int*& j);//�m��6.22
void print(const int* cip);//�m��6.23
void print(const int* beg, const int* end);//�m��6.23//Using the Standard Library Conventions
void print(const int ia[], size_t sz);//�m��6.23//Explicitly Passing a Size Parameter
void print_Array_Reference_Parameters(const int (&arr)[2]);//�m��6.23
void print_Passing_a_Multidimensional_Array_ref(const int (&arr)[2][2]);//�m��6.23
void print_Passing_a_Multidimensional_Array_pointer(const int (*arr)[2], int rowSize);//�m��6.23
void print_Passing_a_Multidimensional_Array_pointer_size_t(const int (*arr)[2], size_t rowSize);//�m��6.23
//�o�̪�int �O�}�C���������O�A���O�}�C���j�p,�ҥH����Ounsigned�A�Ӷ��O���������O�]�b�o�̬Oint�^�C�]���G���}�C�i�ݧ@�Orow�Mcolumn�A�ҥH�~�srowSize
//�Ӧ]�����ШS�����w�j�p�A�S�p�U���Ĥ@���פj�p���ٲ��A�ҥH���t�~�A���ӲĤ@���j�p���Ѽ�
//�Ӧ]���Ĥ@�����������O���}�C�A�ҥH�K�K�]�٬O�h�óo��int�A���ӬOsize_t ��unsinged�����A�]���n�i���j�p�A�~�వ���N�]iterate�^�]�C
//�G�M��size_t�]�i�H�A�B���Ӥ����A�_�h�p�G�O�t�ȡA�o���N�]iterate�^���j����g�~�n�H
void print_Passing_a_Multidimensional_Array_multiArr(const int arr[][2],int rowSize);//�m��6.23

//void print_sum_of_the_elements_in_the_list(initializer_list<int> lst);//�m��6.27





