package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
	"time"
)

func pow10(n int) int64 {
	res := int64(1)
	for i := 0; i < n; i++ {
		res *= 10
	}
	return res
}

func main() {
	start := time.Now()

	f, err := os.Open("../inputs/2.txt")
	if err != nil {
		return
	}

	defer f.Close()

	sc := bufio.NewScanner(f)
	var line string
	for sc.Scan() {
		line = strings.TrimSpace(sc.Text())
		if line != "" {
			break
		}
	}

	if err := sc.Err(); err != nil {
		return
	}

	if line == "" {
		fmt.Println(0)
		fmt.Printf("elapsed: %v\n", time.Since(start))
		return
	}

	type interval struct{ lo, hi int64 }
	var ranges []interval
	for _, part := range strings.Split(line, ",") {
		part = strings.TrimSpace(part)
		if part == "" {
			continue
		}
		ends := strings.Split(part, "-")
		if len(ends) != 2 {
			continue
		}
		lo, _ := strconv.ParseInt(strings.TrimSpace(ends[0]), 10, 64)
		hi, _ := strconv.ParseInt(strings.TrimSpace(ends[1]), 10, 64)
		if lo > hi {
			lo, hi = hi, lo
		}
		ranges = append(ranges, interval{lo, hi})
	}

		seen := make(map[int64]struct{})
	var sum int64

	for _, rg := range ranges {
		L, R := rg.lo, rg.hi
		for k := 1; k <= 9; k++ { 
			pow := pow10(k)
			minHalf := pow / 10
			maxHalf := pow - 1
			d := pow + 1 

			low := (L + d - 1) / d
			high := R / d

			if low < minHalf {
				low = minHalf
			}
			if high > maxHalf {
				high = maxHalf
			}
			if low > high {
				continue
			}

			for a := low; a <= high; a++ {
				val := a*pow + a
				if val >= L && val <= R {
					if _, ok := seen[val]; !ok {
						seen[val] = struct{}{}
						sum += val
					}
				}
			}
		}
	}

	fmt.Println(sum)
	fmt.Printf("elapsed: %v\n", time.Since(start))
}
