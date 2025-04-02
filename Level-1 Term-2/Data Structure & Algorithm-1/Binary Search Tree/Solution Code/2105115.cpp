#include<bits/stdc++.h>

using namespace std;

template<typename T>
class Treenode
{
public:
    T data;
    Treenode<T>* left;
    Treenode<T>* right;

    Treenode(const T& value)
    {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

template<typename T>
class BST
{
private:
    Treenode<T>* root;

public:
    BST()
    {
        root = nullptr;
    }

    void insert(const T& value)
    {
        root = insert(root, value);
    }

    bool search(const T& value)
    {
        return search(root, value);
    }

    void PreOrderTraversal(ostream& outStream)
    {
        PreOrderTraversal(root, outStream);
        outStream << endl;
    }

    void PostOrderTraversal(ostream& outStream)
    {
        PostOrderTraversal(root, outStream);
        outStream << std::endl;
    }

    void InOrderTraversal(ostream& outStream)
    {
        InOrderTraversal(root, outStream);
        outStream << endl;
    }

    void DeleteNode(const T& value)
    {
        root = DeleteNode(root, value);
    }

    void print(ostream& outStream)
    {
        outStream << "(";
        print(root, outStream);
        outStream << ")";
        outStream << endl;
    }

private:
    Treenode<T>* insert(Treenode<T>* root, const T& value)
    {
        if (!root)
        {
            return new Treenode<T>(value);
        }

        if (value < root->data)
        {
            root->left = insert(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = insert(root->right, value);
        }

        return root;
    }

    bool search(Treenode<T>* root, const T& value)
    {
        if (!root)
        {
            return false;
        }

        if (root->data == value)
        {
            return true;
        }
        else if (root->data > value)
        {
            return search(root->left, value);
        }
        else if (root->data < value)
        {
            return search(root->right, value);
        }

        return false;
    }



    Treenode<T>* DeleteNode(Treenode<T>* root, const T& value)
    {
        if (root == NULL)
        {
            return root;
        }

        if (value < root->data)
        {
            root->left = DeleteNode(root->left, value);
        }
        else if (value > root->data)
        {
            root->right = DeleteNode(root->right, value);
        }
        else
        {
            if (root->left == NULL)
            {
                return root->right;
            }
            else if (root->right == NULL)
            {
                return root->left;
            }
            else
            {
                root->data = minVal(root->right);
                root->right = DeleteNode(root->right, root->data);
            }
        }

        return root;
    }

    int minVal(Treenode<T>* root) {
        int minV = root->data;

        while (root->left != NULL) {
            minV = root->left->data;
            root = root->left;
        }

        return minV;
    }

    void PreOrderTraversal(Treenode<T>* root, ostream& outStream)
    {
        if (!root)
        {
            return;
        }
        outStream << root->data << " ";
        PreOrderTraversal(root->left, outStream);
        PreOrderTraversal(root->right, outStream);
    }

    void PostOrderTraversal(Treenode<T>* root, ostream& outStream)
    {
        if (!root)
        {
            return;
        }
        PostOrderTraversal(root->left, outStream);
        PostOrderTraversal(root->right, outStream);
        outStream << root->data << " ";
    }

    void InOrderTraversal(Treenode<T>* root, ostream& outStream)
    {
        if (!root)
        {
            return;
        }
        InOrderTraversal(root->left, outStream);
        outStream << root->data << " ";
        InOrderTraversal(root->right, outStream);
    }

    void print(Treenode<T>* root, ostream& outStream)
    {
        if (!root)
        {
            return;
        }

        outStream << root->data;

        if (root->left || root->right)
        {
            outStream << "(";
            print(root->left, outStream);
            outStream << ",";
            print(root->right, outStream);
            outStream << ")";
        }
    }
};

int main()
{
    BST<int> bst;

    ifstream inputFile("in.txt");
    ofstream outputFile("out.txt");

    if (!inputFile)
    {
        cout << "Error opening the input file." << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error opening the output file." << endl;
        return 1;
    }

    string line;
    while (getline(inputFile, line))
    {
        string first_part, second_part;
        istringstream iss(line);
        iss >> first_part >> second_part;

        if (first_part == "F")
        {
            int val = stoi(second_part);
            outputFile << (bst.search(val) ? "found" : "not found") << endl;
        }
        else if (first_part == "I")
        {
            int val = stoi(second_part);
            bst.insert(val);
            bst.print(outputFile);
        }
        else if (first_part == "D")
        {
            int val = stoi(second_part);
            bst.DeleteNode(val);
            bst.print(outputFile);
        }
        else if (first_part == "T")
        {
            if (second_part == "Pre")
            {
                bst.PreOrderTraversal(outputFile);
            }
            else if (second_part == "Post")
            {
                bst.PostOrderTraversal(outputFile);
            }
            else if (second_part == "In")
            {
                bst.InOrderTraversal(outputFile);
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}



