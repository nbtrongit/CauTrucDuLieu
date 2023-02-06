/*Lab Danh sách liên kết đơn
Họ Tên  : NGUYỄN BẢO TRỌNG
MSSV    : 21880154
*/
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* pNext;
};

/* Yêu cầu 1. Khởi tạo một NODE trong DSLK đơn từ một số nguyên k */
Node* CreateNode(int k)
{
	Node* p = new Node; 
	p->data = k;
  p->pNext = NULL;
	return p;
};

/* Yêu cầu 2. Thêm số nguyên k vào đầu DSLK đơn */
void InsertFirst(Node*& pHead, int k)
{
	Node* p = CreateNode(k);	//Tạo NODE p từ số nguyên k
  if(pHead == NULL)
  {
    pHead = p;
  }
  else
  {
    p->pNext = pHead;
    pHead = p;
  }
}

/* Yêu cầu 3. Thêm số nguyên k vào cuối DSLK đơn */
void InsertLast(Node*& pHead, int k)
{
	Node* p = CreateNode(k);	//Tạo NODE p từ số nguyên k
  Node* pCurrent = pHead;
	while(true)
  {
    if(pHead == NULL)
    {
      pHead = p;
      break;
    }
    else if(pCurrent->pNext == NULL)
    {
      pCurrent->pNext = p;
      break;
    }
    else
    {
      pCurrent = pCurrent->pNext;
    }
  }
};

/* Yêu cầu 4. In toàn bộ số nguyên trong DSLK đơn */
void PrintList(Node* pHead)
{
  Node* pCurrent = pHead;
	while(true)
  {
    cout << pCurrent->data << "\n";
    if(pCurrent->pNext == NULL)
    {
      break;
    }
    else
    {
      pCurrent = pCurrent->pNext;
    }
  }
}

/* Yêu cầu 5. Tìm kiếm số nguyên k trong DSLK đơn. Nếu có trả về true. Ngược lại trả về false */
bool SearchList(Node* pHead, int k)
{
	bool result = false;
  Node* pCurrent = pHead;
  if(pHead == NULL)
  {
    return result;
  }
	while(true)
  {
    if(pCurrent->data == k)
    {
      return true;
    }
    else if(pCurrent->pNext == NULL)
    {
      break;
    }
    else
    {
      pCurrent = pCurrent->pNext;
    }
  }
	return result;
}

/* Yêu cầu 6. Hoàn thành hàm main() theo yêu cầu */
int main()
{
	Node* pHead = NULL;
	int k;
	do
	{
		cout << "Nhap gia tri cua Node (Nhap -1 de ngung thao tac): ";
		cin >> k;		
		if (k != -1)
		{
			/*Thêm k vào CUỐI DSLK đơn - Sinh viên tự hoàn thành đoạn code này*/
      InsertLast(pHead, k);
		}		
	} while (k != -1);
  
  /*In toàn bộ số nguyên trong DSLK đơn*/
  PrintList(pHead);
	
  /*Nhập vào số nguyên k và kiểm tra k có trong DSLK đơn không*/
  cout << "Nhập vào số nguyên k: ";
  int k1;
	cin >> k1;
  string kq = "false";
  if(SearchList(pHead, k1))
  {
    kq = "true";
  }
  cout << kq << "\n";

	return 0;
}