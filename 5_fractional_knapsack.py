def sort(arr):
	for i in range(1,len(arr)):
		key = arr[i]
		j = i
		while j > 0 and arr[j-1]["ratio"] > key["ratio"]:
			j-=1
		
		temp = arr[i]
		arr[i]  = arr[j]
		arr[j] = temp 
	arr.reverse()
	return arr

def knapsack(profit,weight,knapsack):
	max_profit = 0
	p_w_ratio = []
	for i in range(len(profit)):
		p_w_ratio.append({
			"ratio":profit[i]/weight[i],
			"index":i
			})
		
	p_w_ratio = sort(p_w_ratio)
	i = 0
	while i < len(profit) and knapsack > 0:
		index = p_w_ratio[i]["index"]
		if knapsack >= weight[index]:
			knapsack -= weight[index]
			max_profit += profit[index]
		else:
			max_profit += profit[index] * (knapsack/weight[index])
			knapsack = 0
		i+=1

	print("Max Profit: ", max_profit)

profit = [2,14,26,38,50,62,74,86,98,110]
weight =  [2,4,6,8,10,12,14,16,8,10]
print("Profits: ", profit)
print("Weights: ", weight)
print()
knapsack(profit,weight,25)
