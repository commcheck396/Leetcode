class Solution {
    public int minimumRefill(int[] plants, int capacityA, int capacityB) {
        int left = 0, right = plants.length - 1;
        int ans = 0;
        int curA = capacityA, curB = capacityB;

        while(left<=right) {
            if(left==right) {
                // 最终相遇了，达到同一株
                if(curA<plants[left] && curB<plants[left]) {
                        ans++;
                }
                return ans;  
            }

            // A浇水
            if(curA >= plants[left]) {
                curA -= plants[left];
            } else {
                curA = capacityA - plants[left];
                ans++;
            }

             // B浇水
            if(curB >= plants[right]) {
                curB -= plants[right];
            } else {
                curB = capacityB - plants[right];
                ans++;
            }

            // 同时移动
            left++;
            right--;
        }

        return ans;
    }
}