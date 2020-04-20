package main

import (
	"bufio"
	"fmt"
	"io"
	"log"
	"os"
	"strconv"
)

func main() {

	//solve(os.Stdin)
	// for _, v := range solution {
	// 	fmt.Println(v)
	// }

	f, _ := os.Open("5000.txt")
	a := solve(f)
	fmt.Println(a)
}

func solve(r io.Reader) int {
	sc := bufio.NewScanner(r)
	sc.Split(bufio.ScanWords)

	sc.Scan()

	n, err := strconv.Atoi(sc.Text())

	if err != nil {
		log.Fatalf("error: %v. Unable to convert into integer ", err)
	}

	values := make([]int, n)

	for i := 0; i < n; i++ {
		sc.Scan()
		v, err := strconv.Atoi(sc.Text())
		if err != nil {
			log.Fatalf("error: %v. Unable to convert into integer ", err)
		}
		values[i] = v
	}

	weights := make([]int, n)

	for i := 0; i < n; i++ {
		sc.Scan()
		w, err := strconv.Atoi(sc.Text())
		if err != nil {
			log.Fatalf("error: %v. Unable to convert into integer ", err)
		}
		weights[i] = w
	}

	sc.Scan()
	cap, err := strconv.Atoi(sc.Text())

	if err != nil {
		log.Fatalf("error: %v. Unable to convert into integer ", err)
	}

	solution := make([][]int, n)
	solution[0] = make([]int, cap+1)

	if weights[0] <= cap {
		for i := weights[0]; i <= cap; i++ {
			solution[0][i] = values[0]
		}
	}

	for i := 1; i < n; i++ {
		solution[i] = make([]int, cap+1)

		copy(solution[i], solution[i-1])
		for j := weights[i]; j <= cap; j++ {

			if values[i]+solution[i-1][j-weights[i]] > solution[i][j] {
				solution[i][j] = values[i] + solution[i-1][j-weights[i]]
			}
		}
	}

	return solution[n-1][cap]
}

func converter(in, out string) {
	f, _ := os.Open(in)
	sc := bufio.NewScanner(f)
	sc.Split(bufio.ScanWords)

	sc.Scan()

	n, _ := strconv.Atoi(sc.Text())

	sc.Scan()

	cap, _ := strconv.Atoi(sc.Text())

	values := make([]int, n)
	weights := make([]int, n)

	for i := 0; i < n; i++ {
		sc.Scan()
		v, _ := strconv.Atoi(sc.Text())
		values[i] = v
		sc.Scan()
		w, _ := strconv.Atoi(sc.Text())
		weights[i] = w
	}

	fi, err := os.Create(out)
	if err != nil {
		fmt.Println(err)
		f.Close()
		return
	}

	fmt.Fprintln(fi, n)
	fmt.Fprint(fi, values[0])

	for i := 1; i < n; i++ {
		fmt.Fprintf(fi, " %v", values[i])
	}

	fmt.Fprintln(fi, "")
	fmt.Fprint(fi, weights[0])

	for i := 1; i < n; i++ {
		fmt.Fprintf(fi, " %v", weights[i])
	}

	fmt.Fprintln(fi, "")

	fmt.Fprintln(fi, cap)
}
