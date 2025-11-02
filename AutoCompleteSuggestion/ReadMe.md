### Search Auto-Complete suggestions
 - As user types each character or removes each character, top "k" relevant outcomes must be printed
 - The relevancy can be of multiple tyes -> eg: alphabetical, frequency based
 - Provide a way to add words to search database
 - the number "k" must be configurable
 - support concurrency

### Trie
 - children[27] including space
 - string w : last node of word holding the whole string
 - frequency f : number of times the string is requested
 - global function to add words to Trie

### LookUpStrategy
 - Strategy to get top K relevant searches

### Alphabetical Based -> LookUpStrategy
 - TopKMatches
 - DFS to traverse via Trie

### Frequency Based -> LookUpStrategy
 - TopKMatches
 - DFS to traverse via Trie

### SearchComplate
 - Trie : to store the searches -> search database
 - k : configurable, k matches
 - searchWord : active string to store the search string
 - addCharToSearchString: append character to search word
 - removeLastCharFromSearchString : removes last character from search word
 - addMoreWordsToSerachBase : Allow users to add words into search database