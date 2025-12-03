package atd

import (
    "fmt"
)

type FNode struct {
    Key  Item
    Next *FNode
}

var FH *FNode

func AddBef(bef, ad Item) {
    if FH == nil {
        return
    } else {
        if FH.Key == bef {
            a := &FNode{Key: ad, Next: FH}
            FH = a
            return
        }
        t := FH
        for t.Next != nil {
            if t.Next.Key == bef {
                a := &FNode{Key: ad, Next: t.Next}
                t.Next = a
                break
            }
            t = t.Next
        }
    }
}

func AddAft(aft, ad Item) {
    if FH == nil {
        return
    } else {
        t := FH
        for t != nil {
            if t.Key == aft {
                a := &FNode{Key: ad, Next: t.Next}
                t.Next = a
                break
            }
            t = t.Next
        }
    }
}

func AddSta(nw Item) {
    if FH == nil {
        FH = &FNode{Key: nw, Next: nil}
    } else {
        t := &FNode{Key: nw, Next: FH}
        FH = t
    }
}

func AddEnd(nw Item) {
    if FH == nil {
        FH = &FNode{Key: nw, Next: nil}
    } else {
        t := FH
        for t.Next != nil {
            t = t.Next
        }
        temp := &FNode{Key: nw, Next: nil}
        t.Next = temp
    }
}

func PrintList(ha *FNode) {
    if ha == nil {
        return
    }
    t := ha
    for t != nil {
        fmt.Printf("%d ", t.Key)
        t = t.Next
    }
    fmt.Println()
}

func Del(d Item) {
    if FH == nil {
        return
    } else {
        if FH.Key == d {
            temp := FH.Next
            FH = temp
            return
        }
        t := FH
        for t != nil && t.Next != nil {
            if t.Next.Key == d {
                temp := t.Next
                t.Next = t.Next.Next
                temp = nil
                break
            }
            t = t.Next
        }
    }
}

func DelBef(bef Item) {
    if FH == nil {
        return
    } else {
        if FH.Key == bef {
            return
        } else if FH.Next != nil && FH.Next.Key == bef {
            temp := FH.Next
            FH = temp
            return
        }
        t := FH
        for t.Next != nil && t.Next.Next != nil {
            if t.Next.Next.Key == bef {
                temp := t.Next
                t.Next = t.Next.Next
                temp = nil
                break
            }
            t = t.Next
        }
    }
}

func DelAft(aft Item) {
    if FH == nil {
        return
    } else {
        if FH.Key == aft && FH.Next != nil {
            temp := FH.Next
            FH.Next = FH.Next.Next
            temp = nil
            return
        }

        t := FH
        for t.Next != nil {
            if t.Key == aft {
                temp := t.Next
                t.Next = t.Next.Next
                temp = nil
                break
            }
            t = t.Next
        }
    }
}

func DelSta() {
    if FH == nil {
        return
    } else {
        temp := FH.Next
        FH = temp
    }
}

func DelEnd() {
    if FH == nil {
        return
    } else {
        if FH.Next == nil {
            FH = nil
            return
        }
        t := FH
        for t.Next.Next != nil {
            t = t.Next
        }
        t.Next = nil
    }
}

func Search(s Item) bool {
    if FH == nil {
        return false
    } else {
        t := FH
        for t != nil {
            if t.Key == s {
                return true
            }
            t = t.Next
        }
        return false
    }
}