#define ll long long
#define mod 1000000007

class Solution {
public:
    int n;
    int goal;
    ll dp[101][101];
    ll f(int songs, int playlists, int k){
        if(playlists == goal){
            return (songs == n);
        }
        
        if(dp[songs][playlists] != -1) return dp[songs][playlists];
        
        ll ans = 0;
        ans += ((max(0, songs - k))*f(songs, playlists+1, k)) % mod;
        ans += ((n-songs)*f(songs+1, playlists+1, k)%mod)%mod;
        
        ans %= mod;
        return dp[songs][playlists] = ans;
    }
    int numMusicPlaylists(int n, int goal, int k) {
        this->n = n;
        this->goal = goal;
        memset(dp, -1, sizeof(dp));
        return f(0, 0, k);
    }
};