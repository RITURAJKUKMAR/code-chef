
import heapq
import sys

INF = float('inf') 

def dijkstra(N, S, alliances, cost_matrix):

    min_cost = [INF] * N
    min_cost[S] = 0
    

    pq = [(0, S)] 
    
    while pq:
        current_cost, current_planet = heapq.heappop(pq)
        
    
        if current_cost > min_cost[current_planet]:
            continue
        
    
        current_alliance = alliances[current_planet]
        
    
        for target_planet in range(N):
            if target_planet == current_planet:
                continue
            
            target_alliance = alliances[target_planet]
            
        
            travel_cost = cost_matrix[current_planet][target_alliance]
            
            if travel_cost == -1:
                continue 
            
            new_cost = current_cost + travel_cost
            
        
            if new_cost < min_cost[target_planet]:
                min_cost[target_planet] = new_cost
                heapq.heappush(pq, (new_cost, target_planet))
    

    return min_cost

def main():
    input = sys.stdin.read
    data = input().splitlines()
    

    N, K, S = map(int, data[0].split())
    S -= 1 
    

    alliances = list(map(int, data[1].split()))
    alliances = [a - 1 for a in alliances] 
    

    cost_matrix = []
    for i in range(N):
        cost_matrix.append(list(map(int, data[2 + i].split())))
    

    min_cost = dijkstra(N, S, alliances, cost_matrix)
    

    result = []
    for cost in min_cost:
        if cost == INF:
            result.append(-1)
        else:
            result.append(cost)
    
    print(" ".join(map(str, result)))

if __name__ == "__main__":
    main()
