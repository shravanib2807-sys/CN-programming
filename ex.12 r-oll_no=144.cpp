#include <iostream>
using namespace std;

#define INF 999
#define MAX 10

int main()
{
    int n, edges, cost[MAX][MAX];
    int dist[MAX][MAX], next[MAX][MAX];
    int i, j, k, u, v, w, s, d, p;
    char source, destination, a, b;

    cout << "Enter number of sources: ";
    cin >> n;

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            cost[i][j] = (i == j) ? 0 : INF;

    cout << "Enter number of edges: ";
    cin >> edges;

    cout << "Enter source, destination and cost:\n";

    for(i = 0; i < edges; i++)
    {
        cin >> a >> b >> w;

        u = a - 'A';
        v = b - 'A';

        cost[u][v] = w;
        cost[v][u] = w;
    }

    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
        {
            dist[i][j] = cost[i][j];

            if(i != j && cost[i][j] < INF)
                next[i][j] = j;
            else
                next[i][j] = -1;
        }

    for(k = 0; k < n; k++)
        for(i = 0; i < n; i++)
            for(j = 0; j < n; j++)
                if(dist[i][k] < INF && dist[k][j] < INF &&
                   dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    next[i][j] = next[i][k];
                }

    cout << "\nROUTING TABLE\n";
    cout << "Source\t";

    for(i = 0; i < n; i++)
        cout << char('A' + i) << "\t";

    cout << "\n";

    for(i = 0; i < n; i++)
    {
        cout << char('A' + i) << "\t";

        for(j = 0; j < n; j++)
        {
            if(dist[i][j] >= INF)
                cout << "INF\t";
            else
                cout << dist[i][j] << "\t";
        }

        cout << "\n";
    }

    cout << "\nEnter Source (A-" << char('A' + n - 1) << "): ";
    cin >> source;

    cout << "Enter Destination (A-" << char('A' + n - 1) << "): ";
    cin >> destination;

    if(source >= 'a' && source <= 'z')
        source -= 32;

    if(destination >= 'a' && destination <= 'z')
        destination -= 32;

    s = source - 'A';
    d = destination - 'A';

    if(s < 0 || s >= n || d < 0 || d >= n)
    {
        cout << "Invalid source or destination!\n";
        return 0;
    }

    if(s == d)
    {
        cout << "Shortest Path: " << source << "\n";
        cout << "Shortest Distance: 0\n";
    }
    else if(next[s][d] == -1)
    {
        cout << "No path available!\n";
    }
    else
    {
        cout << "\nShortest Path: " << source;
        p = s;

        while(p != d)
        {
            p = next[p][d];
            cout << " -> " << char('A' + p);
        }

        cout << "\nShortest Distance: " << dist[s][d] << "\n";
    }

    return 0;
}
