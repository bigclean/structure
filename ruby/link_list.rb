# link_list.rb --- 
# 
# Filename: link_list.rb
# Description: link list in Ruby way
# Author: Bigclean Cheng
# Created: Mon Apr  09 21:17 2012 (+0800)
# Last-Updated: Mon Apr  09 22:55 2012 (+0800)
# 

# Code:
require 'link_node'

# TODO: add Rdoc for class `LinkList
class LinkList
  def initialize
    @head = LinkNode.new("Head node")
    @tail = LinkNode.new("Tail node")
    # concatenate head and tail node
    puts "Concatenating head and tail nodes..."
    @head.next = @tail
    @tail.prev = @head
  end
  attr_accessor :head, :tail

  def front
    return @head.next
  end

  def back
    return @tail.prev
  end

  def insert_before(next_node, item)
    new_node  = LinkNode.new(item)
    prev_node = next_node.prev

    new_node.prev  = prev_node
    new_node.next  = next_node

    prev_node.next = new_node
    next_node.prev = new_node
  end

  def insert_after(prev_node, item)
    new_node  = LinkNode.new(item)
    next_node = prev_node.next

    new_node.prev  = prev_node
    new_node.next  = next_node

    prev_node.next = new_node
    prev_node.prev = new_node
  end

  def push_front(item)
    self.insert_before(self.front(), item)
  end

  def push_back(item)
    self.insert_after(self.back(), item)
  end

  def pop_front
    self.removeNode(self.front())
  end

  def pop_back
    self.removeNode(self.back())
  end

  def remove_node(aNode)
    prev_node = aNode.prev
    next_node = aNode.next

    if prev_node
      prev_node.next = next_node
    else
      # removed node is head node, so 'next_node' would be started node
      # of original link list, 'next_node' should be placed as new head
      # node of modified link list.
      @head = next_node
    end

    if next_node
      next_node.prev = prev_node
    else
      # removed node is tail node, so 'prev_node' would be last node of
      # original link list, 'prev_node' should be placed as new tail
      # node of modifiied link list.
      @tail = prev_node
    end
  end

  def remove_all_nodes
    self.each {|element| self.remove_node(element) }
  end

  def each
    current = self.front()
    while current.next
      yield current
      current = current.next
    end
  end

end

## vim:set shiftwidth=2:

# 
# link_list.rb ends here
