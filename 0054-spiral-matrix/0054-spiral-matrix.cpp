class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowStart=0,rowEnd=matrix.size()-1;
        int colStart=0,colEnd=matrix[0].size()-1;

        vector<int> ans;
        while(rowStart<rowEnd && colStart<colEnd){
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowStart][i]);
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
            colEnd--;
            for(int i=colEnd;i>=colStart;i--){
                ans.push_back(matrix[rowEnd][i]);
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart;i--){
                ans.push_back(matrix[i][colStart]);
            }
            colStart++;
        }
        if(rowStart==rowEnd){
            for(int i=colStart;i<=colEnd;i++){
                ans.push_back(matrix[rowEnd][i]);
            }
        }else if(colEnd==colStart){
            for(int i=rowStart;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
        }
        return ans;
    }
};