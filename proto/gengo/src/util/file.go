package util

import (
	"bufio"
	"fmt"
	"gengo/config"
	"io"
	"log"
	"os"
	"path/filepath"
	"strings"
)

func FileExists(filename string) bool {
	info, err := os.Stat(filename)
	if os.IsNotExist(err) {
		return false
	}
	return !info.IsDir()
}

func IsProtoFile(fd os.DirEntry) bool {
	if fd.IsDir() || filepath.Ext(fd.Name()) != ".proto" {
		return false
	}
	return true
}

func IsLuaFile(fd os.DirEntry) bool {
	if fd.IsDir() || filepath.Ext(fd.Name()) != ".lua" {
		return false
	}
	return true
}

func Copy(dst string, src string) (written int64, err error) {
	sourceFileStat, err := os.Stat(src)
	if err != nil {
		return 0, err
	}
	if !sourceFileStat.Mode().IsRegular() {
		return 0, fmt.Errorf("%s is not a regular file", src)
	}
	source, err := os.Open(src)
	if err != nil {
		return 0, err
	}
	defer source.Close()
	destination, err := os.Create(dst)
	if err != nil {
		return 0, err
	}
	defer destination.Close()
	nBytes, err := io.Copy(destination, source)
	log.Default().Println(src, " -> ", dst)
	return nBytes, err
}

func GetDstCodeData(cppFileName string) (data []string, err error) {
	var yourCodes []string
	fd, err := os.Open(cppFileName)
	if err != nil {
		return yourCodes, err
	}
	defer fd.Close()
	scanner := bufio.NewScanner(fd)
	var line string
	yourCodeIndex := 0
	for scanner.Scan() {
		line = scanner.Text() + "\n"
		if strings.Contains(line, config.YourCodeBegin) {
			yourCodes = append(yourCodes, line)
		} else if strings.Contains(line, config.YourCodeEnd) {
			yourCodes[yourCodeIndex] += line
			yourCodeIndex += 1
		} else if yourCodeIndex < len(yourCodes) {
			yourCodes[yourCodeIndex] += line
		}
	}
	return yourCodes, err
}
