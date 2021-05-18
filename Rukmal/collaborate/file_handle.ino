void openfile(String filename){
  data_file = SD.open(filename,FILE_READ);
  data_file.seek(44);
  Serial.println("open the file & go to 44th byte");
}

void closefile(String filename){
  data_file.close();
  Serial.println("file closed");
}
