package atd

import (
    "fmt"
)

type Massive struct {
    Ar     []Item
    Index  int
    Length int
}

var M Massive

func Create(len int) {
    arr := make([]Item, len)
    if M.Index > 0 {
        copy(arr, M.Ar)
        M.Ar = arr
        M.Length = len
    } else {
        M.Ar = arr
        M.Length = len
        M.Index = 0
        for i := 0; i < len; i++ {
            M.Ar[i] = 0
        }
    }
}

func AddToInd(inde int, value Item) {
    if inde <= M.Length && inde <= M.Index {
        if inde == M.Length {
            Create(M.Length * 2)
        }

        M.Index++

        if M.Ar[inde] == 0 {
            M.Ar[inde] = value
        } else if M.Index >= M.Length {
            Create(M.Length * 2)
            temp := M.Ar[inde]
            for i := inde + 1; i < M.Length-1; i++ {
                temp1 := M.Ar[i]
                M.Ar[i] = temp
                temp = temp1
            }
            M.Ar[inde] = value
        } else {
            temp := M.Ar[inde]
            for i := inde + 1; i < M.Length-1; i++ {
                temp1 := M.Ar[i]
                M.Ar[i] = temp
                temp = temp1
            }
            M.Ar[inde] = value
        }
    }
}

func AddToEnd(value Item) {
    if M.Index >= M.Length {
        Create(M.Length * 2)
    }

    if M.Index <= M.Length {
        if M.Ar[M.Index] == 0 {
            M.Ar[M.Index] = value
            M.Index++
        }
    }
}

func DelInd(inde int) {
    if inde > M.Length || inde < 0 {
        fmt.Println("Index failure.")
        return
    }

    if M.Ar[inde] != 0 {
        i := inde
        for ; i < M.Length-1; i++ {
            M.Ar[i] = M.Ar[i+1]
        }
        M.Ar[i] = 0
        M.Index--
    } else {
        fmt.Println("This index is already empty.")
    }
}

func Replace(index int, value Item) {
    if index < M.Index-1 && index < M.Length {
        M.Ar[index] = value
    } else {
        fmt.Println("Invalid index!")
    }
}

func Length() int {
    fmt.Println(M.Length)
    return M.Length
}

func Get(index int) Item {
    if index < M.Index-1 {
        return M.Ar[index]
    }
    return 0
}

func PrintArr() {
    for i := 0; i < M.Length; i++ {
        fmt.Printf("%d ", M.Ar[i])
    }
    fmt.Println()
}