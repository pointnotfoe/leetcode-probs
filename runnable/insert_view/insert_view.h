#include <bits/stdc++.h>

/*
Q2 https://leetcode.com/discuss/interview-question/1482144/amazon-online-assessment-september-2021/1095536
You are given a list of entries, where each entry has the following format -

["action", "item_name","item_cost"]

action = Either "INSERT" or "VIEW"
item_name = name of the item (String)
item_cost = cost of the item (String)

Example entries -

[
    ['INSERT','milk','4'],
    ['INSERT','coffee','3'],
    ['VIEW','-','-'],
    ['INSERT','pizza','5'],
    ['INSERT','gum','1'],
    ['VIEW','-','-']
]
VIEW will always be accompanied with hypens. Only INSERT will have item_name and item_cost.
Now, whenever we encounter VIEW, we have to return the item with the minimum cost such that, for first VIEW action, we have to return the item from the database which has the minimum cost, when we encounter second VIEW, we have to return the item from the database which has the second minimum cost

For the above example, milk and coffee are added to the database, when we encounter the first VIEW, we should return coffee as it has the minimum cost amongst coffee and milk, insert pizza and gum to our database and when we encounter VIEW again, we will return the second minimum cost item, which is coffee again.
Hence the final output is
['coffee', 'coffee']

if multiple items have same cost, they are ordered alphabetically ascending

Testcase1
INSERT fries 4
INSERT soda 2
VIEW - - 
VIEW - -
INSERT hamburger 5
VIEW - - 
INSERT nuggets 4
INSERT cookie 1
VIEW - -
VIEW - -

Output - 
soda
fries
hamburger
nuggets
hamburger
1 <= number of entries <= 10^5
1 <= itemname length <= 10
itemnames always lowercase and distinct
1 <= itemcost <= 10^5
*/

using namespace std;

vector<string> insert_view(vector<string> action, vector<string> item, vector<string> cost)
{
    vector<string> view_items;
    std::multimap<int,string> item_map;//sort by cost and allow for duplicate costs
    uint32_t view_count = 0;
    for (int i = 0; i < action.size(); i++)//action, item and cost array have the same size
    {
        if (action[i][0] == 'I')// insert
        {
            //cout << "cost of item "<< i << ") " << item[i]<< " = " << cost[i] << endl;  
            int int_cost = std::stoi(cost[i], nullptr, 10);
            item_map.insert(pair<int,string>(int_cost, item[i]));
        }
        else//view
        {
            std::multimap <int,string>::iterator itr = item_map.begin();
            std::advance(itr, view_count);
            view_items.push_back(itr->second);
            view_count++;
        }
    }
    return view_items;
}