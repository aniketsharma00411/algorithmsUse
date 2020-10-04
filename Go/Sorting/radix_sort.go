// Radix sort is the best algorithm to largest data :)
package main

import (
	"bytes"
	"encoding/binary"
	"fmt"
)

const limitDigit = 4
const maxBitSize = -1 << 31

func main() {

	var testData = []int32{43, 26, 4, -57, 456, 72, -57, 24, 6, 725, 62, -2, -457, 144, 444, 44, 284, 5, 7, -2, -26, 63, -4, 654, 7, -171, 45, 27, -525, -16, -27, 5}
	fmt.Println("Original data: ", testData)
	RadiSort(testData)
	fmt.Println("Result:", testData)
}

func RadiSort(testData []int32) {
	buff := bytes.NewBuffer(nil)
	data := make([][]byte, len(testData))
	for i, e := range testData {
		binary.Write(buff, binary.LittleEndian, e^maxBitSize)
		aux := make([]byte, limitDigit)
		buff.Read(aux)
		data[i] = aux
	}
	sortCountReg := make([][][]byte, 256)
	for i := 0; i < limitDigit; i++ {
		for _, b := range data {
			sortCountReg[b[i]] = append(sortCountReg[b[i]], b)
		}
		j := 0
		for ky, bs := range sortCountReg {
			copy(data[j:], bs)
			j += len(bs)
			sortCountReg[ky] = bs[:0]
		}
	}
	var w int32
	for i, b := range data {
		buff.Write(b)
		binary.Read(buff, binary.LittleEndian, &w)
		testData[i] = w ^ maxBitSize
	}
}
