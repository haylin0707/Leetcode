/*Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.
找出两个长方形全部覆盖的面积，就是两个长方形面积之和减去重复的面积
*/
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int P;int Q;//相交的左下顶点（P,Q)
        int X;int Y;//相交的右上顶点（X,Y）
        P=max(A,E);
        Q=max(B,F);
        X=min(C,G);
        Y=min(D,H);
        
        //相交的面积
        int coverarea=(X-P)*(Y-Q);
        int totalarea=(C-A)*(D-B)+(G-E)*(H-F);
        //当两个长方形没有相交的面积
        if(X<=P || Y<=Q) return totalarea;
        
        int area=totalarea-coverarea;
        return area;
    }
};