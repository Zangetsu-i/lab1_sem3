package main

import (
    "fmt"
    "os"
    "strconv"
    "strings"
)

var currentFilename string

func main() {
    var operation string

    for i := 1; i < len(os.Args); i++ {
        arg := os.Args[i]
        if arg == "--file" {
            if i+1 < len(os.Args) {
                currentFilename = os.Args[i+1]
                i++
            }
        } else if arg == "--query" {
            if i+1 < len(os.Args) {
                operation = os.Args[i+1]
                i++
            }
        }
    }

    req := atd.Config{
        Request: strings.Fields(operation),
    }

    if len(req.Request) == 0 {
        fmt.Println("No command provided")
        return
    }

    fmt.Printf("File: %s Command: %s\n", currentFilename, req.Request[0])

    atd.LoadFromFile(currentFilename)

    if len(req.Request) < 2 {
        fmt.Println("Invalid command format")
        return
    }

    switch req.Request[0][0] {
    case 'S':
        handleStack(req)
    case 'F':
        handleForwardList(req)
    case 'L':
        handleList(req)
    case 'Q':
        handleQueue(req)
    case 'M':
        handleMassive(req)
    default:
        fmt.Printf("Unknown command: %s\n", req.Request[0])
    }

    atd.SaveFile(currentFilename)
}

func handleStack(req atd.Config) {
    if len(req.Request) < 3 && req.Request[0] != "PRINT" {
        fmt.Println("Invalid command for stack")
        return
    }

    switch req.Request[0] {
    case "PUSH":
        val, _ := strconv.Atoi(req.Request[1])
        atd.SPush(atd.Item(val))
    case "POP":
        atd.SPop()
    case "GET":
        val, _ := strconv.Atoi(req.Request[1])
        found := atd.SSearch(atd.Item(val))
        fmt.Printf("Search result: %v\n", found)
    case "PRINT":
        atd.SPrint()
    }
}

func handleForwardList(req atd.Config) {
    switch req.Request[0] {
    case "PUSH":
        val, _ := strconv.Atoi(req.Request[1])
        atd.AddSta(atd.Item(val))
    case "DEL":
        val, _ := strconv.Atoi(req.Request[1])
        atd.Del(atd.Item(val))
    case "GET":
        val, _ := strconv.Atoi(req.Request[1])
        found := atd.Search(atd.Item(val))
        fmt.Printf("Search result: %v\n", found)
    case "PUSHEND":
        val, _ := strconv.Atoi(req.Request[1])
        atd.AddEnd(atd.Item(val))
    case "PUSHAFTER":
        if len(req.Request) < 3 {
            fmt.Println("Invalid PUSHAFTER command")
            return
        }
        ad, _ := strconv.Atoi(req.Request[1])
        aft, _ := strconv.Atoi(req.Request[2])
        atd.AddAft(atd.Item(aft), atd.Item(ad))
    case "PUSHBEFORE":
        if len(req.Request) < 3 {
            fmt.Println("Invalid PUSHBEFORE command")
            return
        }
        ad, _ := strconv.Atoi(req.Request[1])
        bef, _ := strconv.Atoi(req.Request[2])
        atd.AddBef(atd.Item(bef), atd.Item(ad))
    case "DELBEFORE":
        val, _ := strconv.Atoi(req.Request[1])
        atd.DelBef(atd.Item(val))
    case "DELAFTER":
        val, _ := strconv.Atoi(req.Request[1])
        atd.DelAft(atd.Item(val))
    case "DELSTART":
        atd.DelSta()
    case "DELEND":
        atd.DelEnd()
    case "PRINT":
        atd.PrintList(nil)
    }
}

func handleList(req atd.Config) {
    switch req.Request[0] {
    case "PUSH":
        val, _ := strconv.Atoi(req.Request[1])
        atd.LAddSta(atd.Item(val))
    case "DEL":
        val, _ := strconv.Atoi(req.Request[1])
        atd.LDel(atd.Item(val))
    case "GET":
        val, _ := strconv.Atoi(req.Request[1])
        found := atd.LSearch(atd.Item(val))
        fmt.Printf("Search result: %v\n", found)
    case "PUSHEND":
        val, _ := strconv.Atoi(req.Request[1])
        atd.LAddEnd(atd.Item(val))
    case "PUSHAFTER":
        if len(req.Request) < 3 {
            fmt.Println("Invalid PUSHAFTER command")
            return
        }
        ad, _ := strconv.Atoi(req.Request[1])
        aft, _ := strconv.Atoi(req.Request[2])
        atd.LAddAft(atd.Item(aft), atd.Item(ad))
    case "PUSHBEFORE":
        if len(req.Request) < 3 {
            fmt.Println("Invalid PUSHBEFORE command")
            return
        }
        ad, _ := strconv.Atoi(req.Request[1])
        bef, _ := strconv.Atoi(req.Request[2])
        atd.LAddBef(atd.Item(bef), atd.Item(ad))
    case "DELBEFORE":
        val, _ := strconv.Atoi(req.Request[1])
        atd.LDelBef(atd.Item(val))
    case "DELAFTER":
        val, _ := strconv.Atoi(req.Request[1])
        atd.LDelAft(atd.Item(val))
    case "DELSTART":
        atd.LDelSta()
    case "DELEND":
        atd.LDelEnd()
    case "PRINT":
        atd.LPrintList(nil)
    }
}

func handleQueue(req atd.Config) {
    if len(req.Request) < 2 && req.Request[0] != "PRINT" {
        fmt.Println("Invalid command for queue")
        return
    }

    switch req.Request[0] {
    case "PUSH":
        val, _ := strconv.Atoi(req.Request[1])
        atd.QPut(atd.Item(val))
    case "POP":
        atd.QGet()
    case "GET":
        val, _ := strconv.Atoi(req.Request[1])
        found := atd.QSearch(atd.Item(val))
        fmt.Printf("Search result: %v\n", found)
    case "PRINT":
        atd.QPrint()
    }
}

func handleMassive(req atd.Config) {
    switch req.Request[0] {
    case "CREATE":
        val, _ := strconv.Atoi(req.Request[1])
        atd.Create(val)
    case "ADD":
        val, _ := strconv.Atoi(req.Request[1])
        atd.AddToEnd(atd.Item(val))
    case "ADDINDEX":
        if len(req.Request) < 3 {
            fmt.Println("Invalid ADDINDEX command")
            return
        }
        index, _ := strconv.Atoi(req.Request[1])
        val, _ := strconv.Atoi(req.Request[2])
        atd.AddToInd(index, atd.Item(val))
    case "DEL":
        val, _ := strconv.Atoi(req.Request[1])
        atd.DelInd(val)
    case "LENGTH":
        atd.Length()
    case "REPLACE":
        if len(req.Request) < 3 {
            fmt.Println("Invalid REPLACE command")
            return
        }
        index, _ := strconv.Atoi(req.Request[1])
        val, _ := strconv.Atoi(req.Request[2])
        atd.Replace(index, atd.Item(val))
    case "GET":
        index, _ := strconv.Atoi(req.Request[1])
        n := atd.Get(index)
        fmt.Printf("Get result: %d\n", n)
    case "PRINT":
        atd.PrintArr()
    }
}