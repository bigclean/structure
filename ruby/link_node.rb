# link_node.rb --- 
# 
# Filename: link_node.rb
# Description: link node in Ruby way
# Author: Bigclean Cheng
# Created: Mon Apr  09 21:17 2012 (+0800)
# Last-Updated: Mon Apr  09 22:38 2012 (+0800)
# 

# Code:
class LinkNode
  def initialize(item = nil)
    @prev = @next = nil
    @obj = item
  end
  attr_accessor :prev, :next
  attr_accessor :obj
end

## vim:set shiftwidth=2:
#
# 
# link_node.rb ends here
