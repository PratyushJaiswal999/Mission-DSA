#include <bits/stdc++.h>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;

void runningMedian(double number, double &median) {
    
    if (minHeap.size() < maxHeap.size()){
        if (number<median){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeap.push(number);
        }
        else
            minHeap.push(number);
        
        median = ((double) maxHeap.top() + (double)minHeap.top())/2.0;
    }
    
    else if (minHeap.size() > maxHeap.size()){
        if (number>median){
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeap.push(number);
        }
        else
            maxHeap.push(number);

        median = ((double) maxHeap.top() + (double)minHeap.top())/2.0;
    }
    
    else{
        if (number<median){
            maxHeap.push(number);
            median = (double) maxHeap.top();
        }
        else{
            
            minHeap.push(number);               
            median = (double) minHeap.top();    
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    double median = 0;
    double value;
    
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        runningMedian(value, median);
        fout << setprecision(1) << fixed << median << endl;
    }
    fout << "\n";

    fout.close();

    return 0;
}
