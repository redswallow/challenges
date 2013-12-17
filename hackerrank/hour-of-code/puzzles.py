class UnionFind(object):
    """Union-Find is a data structure for keeping track
    of partitions of sets into disjoint subsets"""
 
    def __init__(self):
        """Set up leader and group dictionaries"""
        self.leader = {}  # maps member to group leader
        self.group = {}   # maps group leader to set of members
 
    def makeSet(self, elements):
        """Insert elements as new group"""
        assert type(elements) is list
 
        group = set(elements)
        self.group[elements[0]] = group
        for i in group:
            self.leader[i] = elements[0]
 
    def find(self, element):
        """Return the group associated with an element"""
        return self.leader[element]
 
    def union(self, element1, element2):
        """Merge the groups containing two different elements"""
        leader1 = self.leader[element1]
        leader2 = self.leader[element2]
 
        # If both elements are in same group, do nothing
        if leader1 == leader2:
            return
 
        # Otherwise, merge the two groups
        group1 = self.group[leader1]
        group2 = self.group[leader2]
 
        # Swap names if group1 is smaller than group2
        if len(group1) < len(group2):
            element1, leader1, group1, \
                element2, leader2, group2 = \
                element2, leader2, group2, \
                element1, leader1, group1
 
        # Merge group1 with group2, delete group2 and update leaders
        group1 |= group2
        del self.group[leader2]
        for i in group2:
            self.leader[i] = leader1
 
    def getNumGroups(self):
        """Return the number of groups"""
        return len(self.group)

n,m=(int(i) for i in raw_input().split())
unionFind = UnionFind()
for i in xrange(1,n+1):
    unionFind.makeSet([i])
for mi in xrange(m):
    a,b=(int(i) for i in raw_input().split())
    unionFind.union(a,b)
    if a>b: 
        print unionFind.getNumGroups()


