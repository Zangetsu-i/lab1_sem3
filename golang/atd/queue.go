package atd

import (
    "fmt"
)

type QNode struct {
    Key  Item
    Next *QNode
}

var QHead *QNode
var QTail *QNode

func QPut(item Item) {
    if QHead == nil {
        QHead = &QNode{Key: item, Next: nil}
        QTail = QHead
    } else {
        newNode := &QNode{Key: item, Next: nil}
        QTail.Next = newNode
        QTail = newNode
    }
}

func QGet() Item {
    if QHead == nil {
        return 0
    }
    if QHead == QTail {
        t := QHead.Key
        QHead = nil
        QTail = nil
        return t
    } else if QHead != nil {
        t := QHead.Key
        temp := QHead.Next
        QHead = temp
        return t
    }
    return 0
}

func QSearch(s Item) bool {
    if QHead == nil {
        return false
    }
    temp := QHead
    for temp != nil {
        if temp.Key == s {
            return true
        }
        temp = temp.Next
    }
    return false
}

func QPrint() {
    t := QHead
    for t != nil {
        fmt.Printf("%d ", t.Key)
        t = t.Next
    }
    fmt.Println()
}