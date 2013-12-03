def SegmentString(input, dict, j = 0)
  puts input
  if (dict.include?(input)) 
    return input;
  end
  len = input.length;
  for i in (1...len)
    prefix = input[0...i]
    if (dict.include?(prefix))
      suffix = input[i...len]
      segSuffix = SegmentString(suffix, dict, j+1);
      if (segSuffix)
        return prefix + " " + segSuffix;
      end
    end
  end
  return nil;
end

p SegmentString("aaaab",["a","aa", "aaa", "aaaa"])
