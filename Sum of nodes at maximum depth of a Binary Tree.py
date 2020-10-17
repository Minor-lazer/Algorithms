sum = [0] 
max_level = [-(2**32)] 
  
class createNode:  
      
    def __init__(self, data):  
        self.d = data  
        self.l = None
        self.r = None
  

def sumOfNodesAtMaxDepth(ro, level): 
      
    if(ro == None): 
        return
      
    if(level > max_level[0]): 
        sum[0] = ro . d 
        max_level[0] = level 
      
    elif(level == max_level[0]): 
        sum[0] = sum[0] + ro . d 
      
    sumOfNodesAtMaxDepth(ro . l, level + 1) 
    sumOfNodesAtMaxDepth(ro . r, level + 1)  
      
# Driver Code 
root = createNode(1) 
root.l = createNode(2) 
root.r = createNode(3) 
root.l.l = createNode(4) 
root.l.r = createNode(5) 
root.r.l = createNode(6) 
root.r.r = createNode(7) 
sumOfNodesAtMaxDepth(root, 0) 
print(sum[0]) 
