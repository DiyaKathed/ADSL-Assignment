#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class StockAnalyzer{

    private:
    vector<int> prices;
    vector<int> lowerCount;

    void merge(int low, int mid, int high, vector<pair<int,int>>& arrPair, vector<int>& count){

        vector<pair<int,int>> temp;

        int left = low;
        int right = mid+1;
        int rightCount = 0;

        while(left <= mid && right <= high){

            if(arrPair[left].first <= arrPair[right].first)
            {
                count[arrPair[left].second]+=rightCount;
                temp.push_back(arrPair[left]);
                left++;
            }
            else
            {
                rightCount++;
                temp.push_back(arrPair[right]);
                right++;
            }
        }

        while(left <= mid)
        {
            count[arrPair[left].second] += rightCount;
            temp.push_back(arrPair[left]);
            left++;
        }

        while(right<=high)
        {
            temp.push_back(arrPair[right]);
            right++;
        }

        for(int i=low; i<=high; i++)
            arrPair[i] = temp[i-low];
    }

    void mergeSort(int low, int high, vector<pair<int,int>>& arrPair, vector<int>& count)
    {
        if(low >= high)
            return;

        int mid = (low+high)/2;

        mergeSort(low, mid, arrPair, count);
        mergeSort(mid+1, high, arrPair, count);

        merge(low, mid, high, arrPair, count);
    }

    public:
    void inputPrices()
    {
        int n;
        cout << "\nEnter number of trading days: ";
        cin >> n;
        prices.clear();
        cout << "Enter closing prices:\n";
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            prices.push_back(x);
        }
    }

    void analyze()
    {
        int n = prices.size();
        vector<pair<int,int>> arrPair;
        for(int i=0;i<n;i++){
            arrPair.push_back({prices[i], i});
        }
        lowerCount.assign(n, 0);
        mergeSort(0, n-1, arrPair, lowerCount);
        cout << "\nAnalysis Completed Successfully.\n";
    }

    void displayAnalysis()
    {
        if(prices.empty())
        {
            cout << "\nNo data available.\n";
            return;
        }

        cout << "\n=====================================\n";
        cout << "HISTORICAL STOCK TREND ANALYSIS\n";
        cout << "=====================================\n";

        cout << "Day\tPrice\tFuture Lower Days\n";

        for(int i=0;i<prices.size();i++){
            cout << i+1 << "\t" << prices[i] << "\t" << lowerCount[i] << endl;
        }
    }

    vector<int> getPrices(){
        return prices;
    }

    vector<int> getLowerCount(){
        return lowerCount;
    }
};

void searchDay(StockAnalyzer &obj)
{
    vector<int> prices = obj.getPrices();
    vector<int> count = obj.getLowerCount();

    if(prices.empty()){
        cout<<"\nNo data available.\n";
        return;
    }

    int day;
    cout<<"\nEnter Trading Day (1-"<<prices.size()<<") : ";
    cin>>day;

    if(day < 1 || day > prices.size()){
        cout<<"\nInvalid Day.\n";
        return;
    }

    cout << "\nSearch Result\n";

    cout << "Trading Day : "<<day<<endl;
    cout << "Closing Price : "<<prices[day-1]<<endl;
    cout << "Future Lower Days : "<<count[day-1]<<endl;

    if(count[day-1] == 0)
        cout<<"Trend : Strong"<<endl;
    else if(count[day-1] <= 2)
        cout<<"Trend : Moderate"<<endl;
    else
        cout<<"Trend : Weak"<<endl;
}

void statistics(StockAnalyzer &obj)
{
    vector<int> prices = obj.getPrices();
    vector<int> count = obj.getLowerCount();

    if(prices.empty()){
        cout << "\nNo data available.\n";
        return;
    }

    int highest = prices[0];
    int lowest = prices[0];

    int maxCount = count[0];
    int minCount = count[0];

    double sum = 0;

    for(int i=0;i<prices.size();i++){

        highest = max(highest, prices[i]);
        lowest = min(lowest, prices[i]);

        maxCount = max(maxCount, count[i]);
        minCount = min(minCount, count[i]);

        sum += prices[i];
    }

    cout<<"\n========== Statistics ==========\n";

    cout << "Total Trading Days : " << prices.size() << endl;
    cout << "Highest Price : " << highest << endl;
    cout << "Lowest Price : " << lowest<<endl;
    cout << "Average Price : " << sum/prices.size() << endl;
    cout << "Maximum Lower Count : " << maxCount << endl;
    cout << "Minimum Lower Count : " << minCount << endl;
}

void trendClassification(StockAnalyzer &obj)
{
    vector<int> prices = obj.getPrices();
    vector<int> count = obj.getLowerCount();

    if(prices.empty())
    {
        cout << "\nNo data available.\n";
        return;
    }

    cout << "\n========== Trend Classification ==========\n";
    cout << "Day\tPrice\tCount\tTrend\n";

    for(int i = 0; i < prices.size(); i++)
    {
        string trend;

        if(count[i] == 0)
            trend = "Strong";
        else if(count[i] <= 2)
            trend = "Moderate";
        else
            trend = "Weak";

        cout << i + 1 << "\t"
             << prices[i] << "\t"
             << count[i] << "\t"
             << trend << endl;
    }
}

int main()
{
    StockAnalyzer analyzer;

    int choice;
    bool analyzed = false;

    do
    {
        cout << "\n=========================================\n";
        cout << "      STOCK TREND ANALYZER\n";
        cout << "=========================================\n";
        cout << "1. Enter Stock Prices\n";
        cout << "2. Analyze Stock Trend\n";
        cout << "3. Search by Trading Day\n";
        cout << "4. View Statistics\n";
        cout << "5. Trend Classification\n";
        cout << "6. Exit\n";
        cout << "=========================================\n";
        cout << "Enter Choice : ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                analyzer.inputPrices();
                analyzed = false;
                break;

            case 2:
                analyzer.analyze();
                analyzer.displayAnalysis();
                analyzed = true;
                break;

            case 3:
                if(analyzed)
                    searchDay(analyzer);
                else
                    cout << "\nPlease analyze the stock data first.\n";
                break;

            case 4:
                if(analyzed)
                    statistics(analyzer);
                else
                    cout << "\nPlease analyze the stock data first.\n";
                break;

            case 5:
                if(analyzed)
                    trendClassification(analyzer);
                else
                    cout << "\nPlease analyze the stock data first.\n";
                break;

            case 6:
                cout << "\nThank You for Using Stock Trend Analyzer!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

    } while(choice != 6);

    return 0;
}