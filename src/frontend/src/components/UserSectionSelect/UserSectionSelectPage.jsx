import style from './UserSectionSelectPage.module.css'
import { useNavigate } from "react-router-dom"
import { useEffect, useState } from "react"
import axios from 'axios';

const UserSectionSelectPage = () => {
  const navigate = useNavigate();
  const [loading, setLoading] = useState(true);
  const [eduCount, setEduCount] = useState(null);
  const [psychoCount, setPsychoCount] = useState(null);
  const [funnyCount,  setFunnyCount] = useState(null);

  const testTypeArray = ["education", "psycho", "funny"]

  useEffect( () => {
    const fetchData = async () => {
      try {
        const response = await axios.get('http://5.188.51.63:7500/challenges');
        const dataAPI = response.data
        if ( testTypeArray !== null){
          testTypeArray.map( (testType) => {
            const count = dataAPI.filter(item => item.testType === testType).length;
            switch (testType){
              case 'education':
                setEduCount(count)
                break

              case 'psycho':
                setPsychoCount(count)
                break

              case 'funny':
                setFunnyCount(count)
                break
              default:
            }
            return count
          })
          setLoading(false);
        }
      }
      catch (error) {
        console.error('Error fetching data:', error);
      }
    };
    fetchData();
  }, [])

  if (loading){
    return (
      <div className={style.bodyStyle}></div>
    )
  }

  return (
      <div className={style.bodyStyle}>
        <div className={style.hText}>
          Доступные тесты
        </div>
        <div className={style.imageBox}>
          <div>
            <img src={`${testTypeArray[0]}.png`} alt={`${testTypeArray[0]}.png`} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[0]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[0]}`)}> Education ({eduCount}) </div>
          </div>
          <div>
            <img src={`${testTypeArray[1]}.png`} alt={`${testTypeArray[1]}.png`} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[1]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[1]}`)}>Psychological ({psychoCount})</div>
          </div>
          <div>
            <img src={`${testTypeArray[2]}.png`} alt={`${testTypeArray[2]}.png`} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[2]}`)}/>
            <div className={style.imageCaption} onClick={ ()=>navigate(`/user-subsection-select/${testTypeArray[2]}`)}>Funny ({funnyCount})</div>
          </div>
        </div>
      </div>
  );
}

export default UserSectionSelectPage;
