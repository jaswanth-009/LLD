## LRU Cache
 - Cache should store <key, value> pairs
 - Cache must support 2 functions -> get(key), put(key, value)
 - Cache should have a fixed capacity
 - put calls on existing keys should be treated as a usage
 - Should support multi-threading environment
 - get and put should be addressed in O(1)

## Entities

### Node
 - key
 - value
 - prev
 - next
 - getKey()
 - getValue()
 - getNext()
 - getPrev()
 - setNext()
 - setPrev()

### DoublyLinkedList
 - head
 - tail
 - size
 - getSize()
 - addNode()
 - removeNode()
 - removeLAstNode()
 - printDLL()
 - getLastNode()
 - getHead()

### LRUCache
 - Dll
 - values map to store key <--> Node*
 - capacity
 - get()
 - put()
 - printCache()
