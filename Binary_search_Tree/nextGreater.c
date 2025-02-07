int nextgreater(int gd)
{
    int max=0;
    Node*curr;
    for(curr=root;curr;)
    {
        if(curr->data>gd)
        {
            if(max==0||max>curr->data)
                max=curr->data;
            curr=curr->left;
        }
        else
        {
            curr=curr->right;
        }
    }
    return max;
}
