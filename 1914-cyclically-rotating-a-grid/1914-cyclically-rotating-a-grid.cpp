class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        
        int rowStart=0,rowEnd=grid.size()-1;
        int colStart=0,colEnd=grid[0].size()-1;

        while(rowStart<rowEnd && colStart<colEnd){
            vector<int> arr;
            for(int i=colStart;i<=colEnd;i++){
                arr.push_back(grid[rowStart][i]);
            }

            for(int i=rowStart+1;i<=rowEnd;i++){
                arr.push_back(grid[i][colEnd]);
            }

            for(int i=colEnd-1;i>=colStart;i--){
                arr.push_back(grid[rowEnd][i]);
            }

            for(int i=rowEnd-1;i>=rowStart+1;i--){
                arr.push_back(grid[i][colStart]);
            }
            int nk=k%(arr.size());
            rotate(arr.begin(),arr.begin()+nk,arr.end());
            int idx=0;
            
            for(int i=colStart;i<=colEnd;i++){
                grid[rowStart][i]=arr[idx++];
            }

            for(int i=rowStart+1;i<=rowEnd;i++){
                grid[i][colEnd]=arr[idx++];
            }

            for(int i=colEnd-1;i>=colStart;i--){
                grid[rowEnd][i]=arr[idx++];
            }

            for(int i=rowEnd-1;i>=rowStart+1;i--){
                grid[i][colStart]=arr[idx++];
            }


            rowStart++;
            rowEnd--;
            colStart++;
            colEnd--;
        }
        return grid;
    }
};