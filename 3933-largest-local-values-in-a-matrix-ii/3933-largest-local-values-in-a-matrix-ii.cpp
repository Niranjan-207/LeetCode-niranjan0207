class Solution {
public:
    
    vector<vector<int>> segmentTree;
    
    void build(int node,int low,int high,int row,vector<vector<int>>& matrix){
        if(low==high){   segmentTree[row][node]=matrix[row][low];return;}

        int mid=low+(high-low)/2;
        build(2*node,low,mid,row,matrix);
        build(2*node+1,mid+1,high,row,matrix);

        segmentTree[row][node]=max(segmentTree[row][2*node],segmentTree[row][2*node+1]);
    }

    int search(int node,int tl,int tr,int l,int r,int row){
        if(tl>tr)   return INT_MIN;
        if(l<=tl && tr<=r)  return segmentTree[row][node];
        if(tr<l || tl>r)    return INT_MIN;
        int mid=tl+(tr-tl)/2;
        return max(search(2*node,tl,mid,l,r,row),search(2*node+1,mid+1,tr,l,r,row));
    }

    int countLocalMaximums(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        segmentTree.assign(n,vector<int> (4*m,0));

        for(int i=0;i<n;i++){
            build(1,0,m-1,i,matrix);//node,l,h,row,matrix
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]!=0){
                    int dis=matrix[i][j];
                    int cl=max(0,j-dis);
                    int cr=min(m-1,j+dis);
                    int ru=max(0,i-dis);
                    int rb=min(n-1,i+dis);
                    int localMaxima=INT_MIN;
                    for(int qcr=ru;qcr<=rb;qcr++){
                        if(abs(qcr-i)==dis){
                            //localMaxima=max(localMaxima,search(1,0,m-1,cl+1,cr-1,cr));
                            for(int cc=cl;cc<=cr;cc++){
                                if(abs(cc-j)==dis)  continue;
                                localMaxima=max(localMaxima,matrix[qcr][cc]);
                            }
                        }else{
                            localMaxima=max(localMaxima,search(1,0,m-1,cl,cr,qcr));
                        }
                    }
                    if(localMaxima<=dis) cnt++;
                }
            }
        }
        return cnt;
        
    }
};