#include <iostream>

using namespace std;

void getpreorder(int* inorder, int* postorder, int* preorder, int preleft, int preright, int inleft, int inright, int postleft, int postright){
    int rootindex;
    int leftnumber;
    int rootnumber;
    if (preright > preleft){
        rootnumber = postorder[postright];
        preorder[preleft] = rootnumber;
        for(int i = inleft; i <= inright; i++){
            if (inorder[i] == rootnumber){
                rootindex = i;
            }
        }
        leftnumber = rootindex - inleft;
        getpreorder(inorder, postorder, preorder, preleft + 1, preleft + leftnumber, inleft, inleft + leftnumber - 1, postleft, postleft + leftnumber - 1);
        getpreorder(inorder, postorder, preorder, preleft + leftnumber + 1, preright, inleft + leftnumber + 1, inright, postleft + leftnumber, postright - 1);
    }
    else if (preright == preleft){
        preorder[preleft] = postorder[postright];
    }
}

int main(){
    int size;
    int tmp;
    int* inorder;
    int* postorder;
    int* preorder;

    cin >> size;

    inorder = new int[size];
    postorder = new int[size];
    preorder = new int[size];
    for (int i = 0; i < size; i++){
        cin >> tmp;
        inorder[i] = tmp;
    }
    for (int i = 0; i < size; i++){
        cin >> tmp;
        postorder[i] = tmp;
    }
    getpreorder(inorder, postorder, preorder, 0, size - 1, 0, size - 1, 0, size - 1);
    for (int i = 0; i < size; i++){
        cout << preorder[i] << ' ';
    }
    return 0;
}