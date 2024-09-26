package util

import (
	"strings"

	"golang.org/x/text/cases"
	"golang.org/x/text/language"
)

// CapitalizeWords 将每个单词的首字母大写
func CapitalizeWords(s string) string {
	// 创建一个标题化的转换器
	title := cases.Title(language.English)

	// 分隔字符串为单词
	words := strings.Fields(s)

	// 将每个单词的首字母大写
	for i, word := range words {
		words[i] = title.String(word)
	}

	// 重新组合单词为字符串
	return strings.Join(words, " ")
}