#include "insert_view.h"

int main()
{
    vector<string> result;
    
    result = insert_view(
        {"INSERT","INSERT","VIEW","INSERT","INSERT","VIEW"},
        {"milk", "coffee", "-", "pizza", "gum", "-"},
        {"4", "3", "-", "5", "1", "-"}
    );
    for (uint32_t i = 0; i < result.size(); i++)
    {
        cout << result[i] <<" ";
    }
    cout << endl;

    result = insert_view(
        {"INSERT","INSERT","VIEW","VIEW","INSERT","VIEW","INSERT","INSERT","VIEW","VIEW"},
        {"fries", "soda", "-", "-", "hamburger", "-", "nuggests", "cookie", "-", "-"},
        {"4", "2", "-", "-", "5", "-", "4", "1", "-", "-"}
    );
    for (uint32_t i = 0; i < result.size(); i++)
    {
        cout << result[i] <<" ";
    }
    cout << endl;

    return 0;
}