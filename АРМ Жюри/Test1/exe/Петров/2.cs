private void listView1_ColumnClick(object sender, ColumnClickEventArgs e)
{
   ColHeader clickedCol = (ColHeader)this.listView1.Columns[e.Column];
   clickedCol.ascending = !clickedCol.ascending;
   int numItems = this.listView1.Items.Count;
   this.listView1.BeginUpdate();
   ArrayList SortArray = new ArrayList();
   for (int i = 0; i &lt; numItems; i++)
   {
      //SortWrapper - класс сравнение
      SortArray.Add(new SortWrapper(this.listView1.Items[i], e.Column));
   }
   SortArray.Sort(0, SortArray.Count, new SortWrapper.SortComparer(clickedCol.ascending));
   this.listView1.Items.Clear();
   for (int i = 0; i &lt; numItems; i++)
      this.listView1.Items.Add(((SortWrapper)SortArray[i]).sortItem);
 
   this.listView1.EndUpdate();
}