//Experiment 1: Vector
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> nums;

    nums.push_back(10);
    nums.push_back(20);
    nums.push_back(30);

    cout<<"Size: "<<nums.size()<<endl;

    cout<<"Elements:"<<endl;

    for(int x : nums)
    {
        cout<<x<<" ";
    }

    return 0;
}

//Experiment 2: Vector Traversal
int main()
{
    vector<int> nums = {5,8,1,9,4};

    for(int i=0;i<nums.size();i++)
    {
        cout<<"Index "<<i
            <<" = "
            <<nums[i]
            <<endl;
    }
}

//Experiment 3: Unordered Map
#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
    unordered_map<int,string> student;

    student[101] = "Prasad";
    student[102] = "Rahul";
    student[103] = "Sneha";

    cout<<student[101]<<endl;
    cout<<student[102]<<endl;
}

//Experiment 4: Frequency Counting
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    vector<int> arr =
    {
        1,2,2,3,1,1
    };

    unordered_map<int,int> freq;

    for(int num : arr)
    {
        freq[num]++;
    }

    for(auto x : freq)
    {
        cout
        <<x.first
        <<" appears "
        <<x.second
        <<" times"
        <<endl;
    }
}

//Experiment 5: Set
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(10);

    for(int x : s)
    {
        cout<<x<<" ";
    }
}

//Experiment 6: Unordered Set
#include <iostream>
#include <unordered_set>

using namespace std;

int main()
{
    unordered_set<int> s;

    s.insert(10);
    s.insert(20);
    s.insert(30);

    if(s.find(20)!=s.end())
    {
        cout<<"Found";
    }
    else
    {
        cout<<"Not Found";
    }
}
