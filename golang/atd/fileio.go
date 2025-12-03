package atd

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
    "strings"
)

func LoadFromFile(filename string) {
    file, err := os.Open(filename)
    if err != nil {
        fmt.Println("INFO: Starting with empty structures")
        return
    }
    defer file.Close()

    scanner := bufio.NewScanner(file)
    currentSection := ""

    for scanner.Scan() {
        line := scanner.Text()
        if line == "" {
            continue
        }

        if strings.Contains(line, "=== MASSIVE ===") {
            currentSection = "MASSIVE"
            continue
        } else if strings.Contains(line, "=== STACK ===") {
            currentSection = "STACK"
            continue
        } else if strings.Contains(line, "=== QUEUE ===") {
            currentSection = "QUEUE"
            continue
        } else if strings.Contains(line, "=== FLIST ===") {
            currentSection = "FLIST"
            continue
        } else if strings.Contains(line, "=== LIST ===") {
            currentSection = "LIST"
            continue
        }

        switch currentSection {
        case "MASSIVE":
            fields := strings.Fields(line)
            temp := make([]Item, len(fields))
            cnt := 0
            ind := 0

            for _, field := range fields {
                val, err := strconv.Atoi(field)
                if err != nil {
                    continue
                }
                temp[cnt] = Item(val)
                cnt++
                if val != 0 {
                    ind++
                }
            }

            Create(cnt)
            for i := 0; i < cnt; i++ {
                M.Ar[i] = temp[i]
            }
            M.Length = cnt
            M.Index = ind

        case "STACK":
            fields := strings.Fields(line)
            values := make([]Item, len(fields))

            for i, field := range fields {
                val, err := strconv.Atoi(field)
                if err != nil {
                    continue
                }
                values[i] = Item(val)
            }

            Stack = nil
            for i := len(values) - 1; i >= 0; i-- {
                SPush(values[i])
            }

        case "QUEUE":
            fields := strings.Fields(line)

            QHead = nil
            QTail = nil
            for _, field := range fields {
                val, err := strconv.Atoi(field)
                if err != nil {
                    continue
                }
                QPut(Item(val))
            }

        case "FLIST":
            fields := strings.Fields(line)

            FH = nil
            for _, field := range fields {
                val, err := strconv.Atoi(field)
                if err != nil {
                    continue
                }
                AddEnd(Item(val))
            }

        case "LIST":
            fields := strings.Fields(line)

            LH = nil
            for _, field := range fields {
                val, err := strconv.Atoi(field)
                if err != nil {
                    continue
                }
                LAddEnd(Item(val))
            }
        }
    }

    fmt.Printf("Data loaded from %s\n", filename)
}

func SaveFile(filename string) {
    file, err := os.Create(filename)
    if err != nil {
        fmt.Printf("%s could not be opened --bye.\n", filename)
        os.Exit(1)
    }
    defer file.Close()

    writer := bufio.NewWriter(file)

    writer.WriteString("=== MASSIVE ===\n")
    for i := 0; i < M.Length; i++ {
        writer.WriteString(fmt.Sprintf("%d ", M.Ar[i]))
    }
    writer.WriteString("\n")

    writer.WriteString("=== STACK ===\n")
    stackTemp := Stack
    for stackTemp != nil {
        writer.WriteString(fmt.Sprintf("%d ", stackTemp.Key))
        stackTemp = stackTemp.Next
    }
    writer.WriteString("\n")

    writer.WriteString("=== QUEUE ===\n")
    queueTemp := QHead
    for queueTemp != nil {
        writer.WriteString(fmt.Sprintf("%d ", queueTemp.Key))
        queueTemp = queueTemp.Next
    }
    writer.WriteString("\n")

    writer.WriteString("=== FLIST ===\n")
    flistTemp := FH
    for flistTemp != nil {
        writer.WriteString(fmt.Sprintf("%d ", flistTemp.Key))
        flistTemp = flistTemp.Next
    }
    writer.WriteString("\n")

    writer.WriteString("=== LIST ===\n")
    listTemp := LH
    for listTemp != nil {
        writer.WriteString(fmt.Sprintf("%d ", listTemp.Key))
        listTemp = listTemp.Next
    }
    writer.WriteString("\n")

    writer.Flush()
    fmt.Printf("Data saved to %s\n", filename)
}