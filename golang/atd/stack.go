package atd

import (
    "fmt"
)

type SNode struct {
    Key  Item
    Next *SNode
}

var Stack *SNode

func SPush(item Item) {
    if Stack == nil {
        Stack = &SNode{Key: item, Next: nil}
    } else {
        t := &SNode{Key: item, Next: Stack}
        Stack = t
    }
}

func SPop() Item {
    if Stack != nil {
        temp := Stack.Key
        t := Stack.Next
        Stack = t
        return temp
    }
    return 0
}

func SSearch(s Item) bool {
    if Stack == nil {
        return false
    }
    temp := Stack
    for temp != nil {
        if temp.Key == s {
            return true
        }
        temp = temp.Next
    }
    return false
}

func SPrint() {
    t := Stack
    for t != nil {
        fmt.Printf("%d ", t.Key)
        t = t.Next
    }
    fmt.Println()
}