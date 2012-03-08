-- LinkList.lua ---
--
-- Filename: LinkList.lua
-- Description: double link list demo in Lua
-- Author: Bigclean Cheng
-- Created: Thu Mar 08 23:30 2012
-- Last-Updated: Thu Mar 08 23:30 2012

-- Code:

-- create an empty table
-- assign member functions
LinkList = {}

-- class functions
function LinkList:new()
    -- table 'core' to store head and tail node when constructing
    local core = {
                  head = {prev = nil, obj = "Head Node"},
                  tail = {next = nil, obj = "Tail node"}
              }

    -- concatenate head and tail node
    print("Concatenating head and tail nodes...")
    core.head.next = core.tail
    core.tail.prev = core.head

    --[[
    using annonymous metatable as metatable of 'core' table
    inheriting member functions of global table 'LinkList'.
    --]]
    setmetatable(core, {__index = LinkList})

    return core
end

function LinkList:front()
    return self.head.next
end

function LinkList:back()
    return self.tail.prev
end

function LinkList:insertBefore(nextNode, item)
    local newNode  = {obj = item}
    local prevNode = nextNode.prev

    newNode.prev  = prevNode
    newNode.next  = nextNode

    prevNode.next = newNode
    nextNode.prev = newNode
end

function LinkList:insertAfter(prevNode, item)
    local newNode  = {obj = item}
    local nextNode = prevNode.next

    newNode.prev  = prevNode
    newNode.next  = nextNode

    prevNode.next = newNode
    prevNode.prev = newNode
end

function LinkList:pushFront(item)
    self:insertBefore(self:front(), item)
end

function LinkList:pushBack(item)
    self:insertAfter(self:back(), item)
end

function LinkList:popFront()
    self:removeNode(self:front())
end

function LinkList:popBack()
    self:removeNode(self:back())
end

function LinkList:removeNode(aNode)
    local prevNode = aNode.prev
    local nextNode = aNode.next

    if prevNode then
        prevNode.next = nextNode
    else
        --[[
        removed node is head node, so 'nextNode' would be started node
        of original link list, 'nextNode' should be placed as new head
        node of modified link list.
        --]]
        self.head = nextNode
    end

    if nextNode then
        nextNode.prev = prevNode
    else
        --[[
        removed node is tail node, so 'prevNode' would be last node of
        original link list, 'prevNode' should be placed as new tail
        node of modifiied link list.
        --]]
        self.tail = prevNode
    end
end

function LinkList:removeAllNodes()
    for element in self:iter() do
        self:removeNode(element)
    end
end

-- iterator implemented in closure
function LinkList:iter()
    --[[
    local upvalue in this closure: 'current', 'tmp' and 'self'
    iter() equals '__iter__' and 'next' function in Python version.
    --]]
    local current = self:front()
    local tmp = nil
    -- lambda calculation
    return function ()
        tmp = current
        if tmp.next then
            current = current.next
            return tmp
        end
    end
end

-- LinkList.lua ends here
