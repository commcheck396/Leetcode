class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int left = 0, right = plants.length - 1;
        int ans = 0;
        int curA = capacityA, curB = capacityB;

        while(left<=right) {
            if(left==right) {
                // ���������ˣ��ﵽͬһ��
                if(curA<plants[left] && curB<plants[left]) {
                        ans++;
                }
                return ans;  
            }

            // A��ˮ
            if(curA >= plants[left]) {
                curA -= plants[left];
            } else {
                curA = capacityA - plants[left];
                ans++;
            }

             // B��ˮ
            if(curB >= plants[right]) {
                curB -= plants[right];
            } else {
                curB = capacityB - plants[right];
                ans++;
            }

            // ͬʱ�ƶ�
            left++;
            right--;
        }

        return ans;
    }
}