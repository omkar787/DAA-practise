# Karp's NP complete Problem
# Other applications include
    # - set covering 
    # - vertex covering

'''
    Time complexity  = O (n)  .... best
                       O (mn) .... worst

    Space complexity = O(m) ..... where m is the size of selected_subsets
'''


universal_set = {1, 2, 3, 4, 5}
subsets = {
    frozenset({4, 1, 3}): 5,
    frozenset({2, 5}): 10,
    frozenset({1,2,3}):1,
    frozenset({4,5}):1,
    frozenset({1, 4, 3, 2}): 3
}


def set_cover(universal_set,subsets):
    to_cover  = universal_set
    minimum_cost = 0
    selected_subset = []

    while to_cover:
        best_set  = max(subsets,key=lambda s: len(s & universal_set))
        selected_subset.append(best_set)
        minimum_cost += subsets[best_set]
        del subsets[best_set]
        to_cover -= best_set
    
    return minimum_cost,selected_subset

print(set_cover(universal_set,subsets))

