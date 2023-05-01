def kmp(text, pattern):
  n = len(text)
  m = len(pattern)
  prefix = [0] * (m + 1)
  k = 0
  for i in range(2, m + 1):
    while k > 0 and pattern[k] != pattern[i - 1]:
      k = prefix[k]
    if pattern[k] == pattern[i - 1]:
      k += 1
    prefix[i] = k
  i = 0
  j = 0
  while i < n and j < m:
    if text[i] == pattern[j]:
      i += 1
      j += 1
    elif j > 0:
      j = prefix[j]
    else:
      i += 1
  if j == m:
    return i - m
  else:
    return -1
  
text = "ababdabacdababcabab"
pattern = "ababcabab"
result = kmp(text, pattern)
print("Text string = " ,text)
print("Pattern string = " ,pattern)
if result != -1:
  print(f"Pattern found at index {result} in the text.")
else:
  print("Pattern not found in the text.")