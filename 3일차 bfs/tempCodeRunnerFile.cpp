for (i = 1; i <= n; i++) {
        arr[i-1].push_back(-2);
        arr.push_back(vector<int>(-2));
        
        for (j = 0; j < m; j++) {
            scanf(" %d", &k);
            arr[i].push_back(k);
        }
    }