    // while (!q.empty()) {
    //     int cnt = q.front();
    //     q.pop();

    //     for (int i = 1; i <= n; i++) {
    //         int next = history[cnt][i];

    //         if (next == number && check[next] == false) {
    //             check[next] = true;

    //             history[start][next] = number;
    //             history[cnt][next] = number;

    //             q.push(next);
    //         }
    //     }
    // }