class AuctionSystem {
public:
    unordered_map<int,unordered_map<int,int>>m;
    unordered_map<int,set<pair<int,int>>>s;
    AuctionSystem() {
        
    }
    
    void addBid(int userId, int itemId, int bidAmount) {
        int old_bid=m[itemId][userId];
        if(m[itemId].count(userId)){s[itemId].erase({old_bid,userId});}
        m[itemId][userId]=bidAmount;
        s[itemId].insert({bidAmount,userId});
    }
    
    void updateBid(int userId, int itemId, int newAmount) {
       addBid( userId,  itemId, newAmount);
    }
    
    void removeBid(int userId, int itemId) {
        s[itemId].erase({m[itemId][userId],userId});
        m[itemId].erase(userId);
    }
    
    int getHighestBidder(int itemId) {
        return s[itemId].empty()? -1: s[itemId].rbegin()->second;
    }
};

/**
 * Your AuctionSystem object will be instantiated and called as such:
 * AuctionSystem* obj = new AuctionSystem();
 * obj->addBid(userId,itemId,bidAmount);
 * obj->updateBid(userId,itemId,newAmount);
 * obj->removeBid(userId,itemId);
 * int param_4 = obj->getHighestBidder(itemId);
 */