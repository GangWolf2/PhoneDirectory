#include "PhoneDirectory.h";
#include "PhoneItem.cpp";
#include <iostream>

PhoneDirectory::PhoneDirectory(){
    root = NULL;
}

void PhoneDirectory::print(){
  std::cout << "\nPrinting current directory\n";
  if(root == NULL){
    std::cout << "Tree is empty\n";
  }
  else{
    printHelper(root);
    std::cout << "\n";
  }
}

void PhoneDirectory::printHelper(PhoneItem* currentPhone){
    if(currentPhone == NULL){
        std::cout << " ";
    }
    else{
        printHelper(currentPhone->left);

        std::cout << "Name: " << currentPhone->phoneName <<"\nNumber: " << currentPhone->phoneNumber << "\n";
        printHelper(currentPhone->right);
    }
}

//if the PhoneDirectory is currently NULL, initializes the directory with a new PhoneItem* leaf node
void PhoneDirectory::insert(std::string name, long number){
    if(root == NULL){
        root = leaf(name, number);
    }
    else{
        insertHelper(name, number, root);
    }

}
//called from PhoneDirectory::insert if new PhoneItem leaf is being inserted somewhere else than root
void PhoneDirectory::insertHelper(std::string name, long number, PhoneItem* currentPhone){
    /*if name argument is less than/equal than the name of current node in the BST and left subtree is not NULL
    move down the left subtree
    */
    if(name <= currentPhone->phoneName){
        if(currentPhone->left != NULL){
            insertHelper(name, number, currentPhone -> left);
        }
        //if left subtree is NULL, insert new PhoneItem* leaf into PhoneDirectory at that position
        else{
            currentPhone->left = leaf(name, number);
        }
    }

    /*if name argument is greater than/equal to the name of current node in the BST and right subtree is not NULL
    move down the right subtree
    */
    else if(name >= currentPhone->phoneName){
        if(currentPhone->right != NULL){
            insertHelper(name, number, currentPhone->right);
        }
        //if right subtree is NULL, insert new PhoneItem* leaf into PhoneDirectory at that position
        else{
            currentPhone->right = leaf(name, number);
        }
    }
}
//handles case of when the name being searched is the root node
void PhoneDirectory::del(std::string name){
    if(root->phoneName == name){
        if(root->right != NULL){
            delete root;
            root = twoChild(1, name, root->right);
        }

        else{
            delete root;
            root = twoChild(0, name, root->left);
        }
    }

    else{
        if(name < root->phoneName){
            delHelper(name, root->left);
        }
        if(name > root->phoneName){
            delHelper(name, root->right);
        }
    }
    
}

//handles all other cases of deletion not involving the root node
//Currently causing segmentation faults or not deleting and preserving the right nodes
void PhoneDirectory::delHelper(std::string name, PhoneItem* currentNode){
    PhoneItem* holder = leaf("Holder", 0);
    //When delHelper has reached a NULL node, the name entered does not currently exist in tree
    if(currentNode == NULL){
        std::cout << "ERROR: Tree is either empty, or maximum tree depth reached without a matching the entered name.";
    }

    else if(currentNode->phoneName == name){
        //leaf case: When node is leaf, can be deleted from tree with no issues
        if(currentNode->left == NULL && currentNode->right == NULL){
            delete currentNode;
            currentNode = NULL;
            std::cout << "PhoneItem " << name << " deleted!";
        }
        //one child left case: When node has one child in left subtree, the value in currentNode becomes the value of its left subtree
        else if(currentNode->left != NULL && currentNode->right == NULL){
            holder = currentNode->left;
            delete currentNode;
            currentNode = holder;
        }
        //one child right case: When node has one child in right subtree, the value in currentNode becomes the value of its right subtree
        else if(currentNode->left == NULL && currentNode -> right != NULL){
            delete currentNode;
            currentNode = currentNode->right;
        }
        else{
            //if the same is not equal to current node and less than the current name, traverse the left subtree
            if(name < currentNode->phoneName){
                delHelper(name, currentNode->left);
            }
            //if the same is not equal to current node and greater than the current name, traverse the right subtree
            else if(name > currentNode->phoneName){
                delHelper(name, currentNode->right);
            }
               
        }
    }
   
}

//handles the case in which the contact being searched for is the root node
long PhoneDirectory::search(std::string name){
    std::cout << "\nSearching through the directory for " << name << ": ";
    if(root->phoneName == name){
        std::cout << "Phone Number: " << root->phoneNumber <<"\n";
        return root->phoneNumber;
    }
    else{
        return searchHelper(name, root);
        std::cout << "\n";
    }
}

//handles other cases in which tree must be traversed in order to find contact
long PhoneDirectory::searchHelper(std::string name, PhoneItem* currentPhone){
    //case if contact not found
    if(currentPhone == NULL){
        std::cout << "ERROR: Tree is either empty, or maximum tree depth reached without a matching the entered name.";
        return (-1);
    }
    //case when contact is found
    else if(currentPhone->phoneName == name){
        return currentPhone->phoneNumber;  
    }
    else{
        //traverses down the left subtree of the current node and tests again
        if(name < currentPhone->phoneName){
            return searchHelper(name,currentPhone->left);
        }
        //traverses down the right subtree of the current node and tests again
        else if(name > currentPhone->phoneName){
            return searchHelper(name,currentPhone->right);
        }
    }

}

//lr determines which subtree is passed in from a root node, 0 = left node, 1 = right node
//Needed to find the closest precessor or sucessor to replace node with two children, and knowing
//what subtree we are in makes process easier to travel path
PhoneItem* PhoneDirectory::twoChild(int lr, std::string name, PhoneItem* root){
    //finds the smallest child of a node as the replacement for a deleted root or node with two children
    if(lr == 0){
        while(root->left != NULL){
            root = root->left;
        }
    }
    //finds the largest child of a node as the replacement for a deleted root or node with two children
    else if(lr == 1){
        while(root->right != NULL){
            root = root->right;
        }
    }
    return root;
}
