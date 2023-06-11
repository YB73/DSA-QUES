class SnapshotArray {
public:
    int snapID;
    vector<vector<pair<int, int>>> historyRec;
    
    SnapshotArray(int length) {
    snapID=0;
        historyRec.resize(length);
          for (int i = 0; i < length; ++i) {
            historyRec[i].push_back(make_pair(0, 0));
        }
    }
    
    void set(int index, int val) {
        historyRec[index].push_back(make_pair(snapID, val));
    }
    
    int snap() {
         return snapID++;
    }
    
    int get(int index, int snap_id) {
         auto it = upper_bound(historyRec[index].begin(), historyRec[index].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */