class Solution {
public:
    struct mycomp{
		bool operator()(const pair<string,int> &p1 ,const pair<string,int> &p2){

		if(p1.second!=p2.second)
			return p1.second>p2.second;
		else
			return p1.first<p2.first;
		}
	};
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,mycomp> ans;
		unordered_map<string,int> mp;

		for(string c:words)
			mp[c]++;

		int i=k;

		for(auto it = mp.begin();it!=mp.end();it++){
			ans.push({it->first,it->second});
			if(ans.size()>k)    ans.pop();
		}

		vector<string> v(i);
		while(!ans.empty()){
			v[--i] = ans.top().first;
			ans.pop();
		}

		return v;
    }
};