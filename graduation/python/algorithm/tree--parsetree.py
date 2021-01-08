#!/usr/bin/env eepython
#(       -->            create left child,  push
#+ - * / --> set value, create right child, push
#0-9     --> set value,                     pop
#)       -->                                pop
print os.path.dirname(sys.argv[1])
print os.path.realpath(os.path.dirname(sys.argv[1]))
sys.path.append(os.path.realpath(os.path.dirname(sys.argv[1])))
import stack
import binaryTree

def buildParseTree(fpexp):
    fplist = fpexp.split()
    pStack = stack.Stack()
    eTree = binaryTree.BinaryTree('')
    pStack.push(eTree)
    currentTree = eTree
    for i in fplist:
        if i == '(':
            currentTree.insertLeft('')
            pStack.push(currentTree)
            currentTree = currentTree.getLeftChild()
        elif i not in ['+', '-', '*', '/', ')']:
            currentTree.setRootVal(int(i))
            parent = pStack.pop()
            currentTree = parent
        elif i in ['+', '-', '*', '/']:
            currentTree.setRootVal(i)
            currentTree.insertRight('')
            pStack.push(currentTree)
            currentTree = currentTree.getRightChild()
        elif i == ')':
            currentTree = pStack.pop()
        else:
            raise ValueError
    return eTree

pt = buildParseTree("( 1 + 2 )"); pt.postorder(); print pt
pt = buildParseTree("( ( 1 + 2 ) * 3 )"); pt.postorder()
pt = buildParseTree("( ( 1 + 2 ) * ( 3 + 4 ) )"); pt.postorder()
