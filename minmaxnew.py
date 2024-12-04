import math
def minimax(depth, nodeIndex, isMaximizing, scores, height):
    if depth == height:
        return scores[nodeIndex]
    if isMaximizing:
        leftChild = minimax(depth + 1, nodeIndex * 2, False, scores, height)
        rightChild = minimax(depth + 1, nodeIndex * 2 + 1, False, scores, height)
        return max(leftChild, rightChild)
    else:
        leftChild = minimax(depth + 1, nodeIndex * 2, True, scores, height)
        rightChild = minimax(depth + 1, nodeIndex * 2 + 1, True, scores, height)
        return min(leftChild, rightChild)
if __name__ == "__main__":
    scores = [3, 5, 6, 9, 1, 2, 0, -1]
    height = math.ceil(math.log2(len(scores)))
    print("The optimal value is:", minimax(0, 0, True, scores, height))
