package atd

import (
    "fmt"
)

type LNode struct {
    Prev *LNode
    Key  Item
    Next *LNode
}

var LH *LNode

func LAddBef(bef, ad Item) {
    if LH == nil {
        return
    } else {
        current := LH
        for current != nil {
            if current.Key == bef {
                t := &LNode{Prev: nil, Key: ad, Next: nil}
                t.Next = current
                t.Prev = current.Prev

                if current.Prev != nil {
                    current.Prev.Next = t
                } else {
                    LH = t
                }
                current.Prev = t

                break
            }
            current = current.Next
        }
    }
}

func LAddAft(aft, ad Item) {
    if LH == nil {
        return
    } else {
        ha := LH
        for ha != nil {
            if ha.Key == aft {
                t := &LNode{Prev: nil, Key: ad, Next: nil}
                t.Next = ha.Next
                if ha.Next != nil {
                    ha.Next.Prev = t
                }
                ha.Next = t
                t.Prev = ha
                break
            }
            ha = ha.Next
        }
    }
}

func LAddSta(nw Item) {
    if LH == nil {
        LH = &LNode{Prev: nil, Key: nw, Next: nil}
    } else {
        t := &LNode{Prev: nil, Key: nw, Next: nil}
        t.Next = LH
        LH.Prev = t
        LH = t
    }
}

func LAddEnd(nw Item) {
    ha := LH
    if LH == nil {
        LH = &LNode{Prev: nil, Key: nw, Next: nil}
    } else {
        t := &LNode{Prev: nil, Key: nw, Next: nil}
        for ha.Next != nil {
            ha = ha.Next
        }
        ha.Next = t
        t.Prev = ha
        ha = t
    }
}

func LPrintList(def *LNode) {
    ha := def
    if def == nil {
        ha = LH
    }

    for ha != nil {
        fmt.Printf("%d ", ha.Key)
        ha = ha.Next
    }
    fmt.Println()
}

func LDel(d Item) {
    if LH == nil {
        return
    } else {
        if LH.Key == d && LH.Next != nil {
            temp := LH
            LH.Next.Prev = nil
            LH = LH.Next
            temp = nil
            return
        } else if LH.Next == nil && LH.Key == d {
            LH = nil
            return
        }
        ha := LH
        for ha != nil {
            if ha.Key == d && ha.Next != nil {
                temp := ha
                ha.Next.Prev = ha.Prev
                ha.Prev.Next = ha.Next
                temp = nil
                break
            } else if ha.Next == nil && ha.Key == d {
                temp := ha
                ha.Prev.Next = ha.Next
                temp = nil
                break
            }
            ha = ha.Next
        }
    }
}

func LSearch(s Item) bool {
    ha := LH
    for ha != nil {
        if ha.Key == s {
            return true
        }
        ha = ha.Next
    }
    return false
}

func LDelBef(bef Item) {
    if LH == nil {
        return
    } else {
        if LH.Key == bef {
            return
        }
        current := LH
        for current != nil {
            if current.Next != nil && current.Next.Key == bef {
                if current.Prev != nil {
                    current.Prev.Next = current.Next
                } else {
                    LH = current.Next
                }
                if current.Next != nil {
                    current.Next.Prev = current.Prev
                }
                current = nil
                return
            }
            current = current.Next
        }
    }
}

func LDelAft(aft Item) {
    if LH == nil {
        return
    } else {
        ha := LH
        for ha.Next != nil {
            if ha.Key == aft {
                if ha.Next.Next != nil {
                    temp := ha.Next
                    ha.Next = ha.Next.Next
                    ha.Next.Next.Prev = ha
                    temp = nil
                    return
                }
            }
            ha = ha.Next
        }
    }
}

func LDelSta() {
    if LH == nil {
        return
    } else if LH.Next == nil {
        LH = nil
        return
    } else {
        temp := LH
        LH.Next.Prev = nil
        LH = LH.Next
        temp = nil
    }
}

func LDelEnd() {
    if LH == nil {
        return
    } else {
        current := LH
        for current.Next != nil {
            current = current.Next
        }
        if current.Prev != nil {
            current.Prev.Next = nil
        } else {
            LH = nil
        }
        current = nil
    }
}